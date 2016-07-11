/*
 * evo_util.cpp
 *
 *  Created on: Jun 27, 2016
 *      Author: Tony
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "evo_util.h"
//do I really have to know/send one more parameter as an separated int?

::capnp::MallocMessageBuilder* makeMsgPack(vector<Request> reqList) {
	::capnp::MallocMessageBuilder* messageZU = new capnp::MallocMessageBuilder;
	ZEMessage::Builder zemBuilder = messageZU->initRoot<ZEMessage>();
	//KVRequest::Builder reqBuilder = message.initRoot<KVRequest>();
	int nReq = reqList.size();
	::capnp::List<KVRequest>::Builder reqListBdr = zemBuilder.initListMsg(nReq);

	for(int i=0; i< nReq; i++){
		reqListBdr[i].setKey(reqList.at(i).key.c_str());
		reqListBdr[i].setVal(reqList.at(i).val.c_str());
		reqListBdr[i].setOpcode(reqList.at(i).opCode.c_str());
	}
	zemBuilder.setNRequest(nReq);
	return messageZU;
}



int msgToBuff(capnp::MessageBuilder *msg, void* &to_capn_str, size_t &len) {
	int result = 0;
	kj::Array<capnp::word> words = messageToFlatArray(*msg);
	kj::ArrayPtr<kj::byte> bytes = words.asBytes();
	size_t nbytes = bytes.size();

	if ( NULL == to_capn_str) {
		len = nbytes;
		to_capn_str = (void*) malloc(nbytes);
	}

	if (nbytes <= len) { //error again?
		memcpy(to_capn_str, bytes.begin(), nbytes);
		//meltresult_success(result);
	} else {
		len = nbytes;
	}
	return result;
}

capnp::FlatArrayMessageReader* buffToMsgReader(const void* from_capn_str,
		size_t len) {
	size_t nwords = len / sizeof(capnp::word);
	kj::ArrayPtr<const capnp::word> words(
			reinterpret_cast<const capnp::word*>(from_capn_str), nwords);
	capnp::FlatArrayMessageReader* msg = NULL;
	msg = new capnp::FlatArrayMessageReader(words);
	if ( NULL == msg) {
		cout << "FlatArrayMessageReader msg error!" << endl;
	}
	return msg;
}

ZEMessage::Reader getZEMsgReader(const void* from_capn_str, int capnStrSize) {

	capnp::FlatArrayMessageReader* data_in = buffToMsgReader(from_capn_str,
			capnStrSize);
	ZEMessage::Reader zemReader = data_in->getRoot<ZEMessage>();

	return zemReader;
}

vector<Request> extrReqVector(const void* from_capn_str, int capnStrSize){

	vector<Request> reqList;// = new vector<Request>;

	ZEMessage::Reader zemReader = getZEMsgReader(from_capn_str,  capnStrSize);

	for(KVRequest::Reader req : zemReader.getListMsg()){
		Request newReq;
		newReq.key = string(req.getKey());
		newReq.val = string(req.getVal());
		newReq.opCode = string(req.getOpcode());
		reqList.push_back(newReq);
	}

	return reqList;

}





