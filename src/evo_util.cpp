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

::capnp::MallocMessageBuilder* makeMsgPack(vector<Request> reqList) {

	::capnp::MallocMessageBuilder* messageZU = new capnp::MallocMessageBuilder;

	ZEMessage::Builder zemBuilder = messageZU->initRoot<ZEMessage>();

	int nReq = reqList.size();

	::capnp::List<KVRequest>::Builder reqListBdr = zemBuilder.initListMsg(nReq);

	for (int i = 0; i < nReq; i++) {

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

vector<Request> extrReqVector(const void* from_capn_str, int capnStrSize) {

	vector<Request> reqList;

	ZEMessage::Reader zemReader = getZEMsgReader(from_capn_str, capnStrSize);

	for (KVRequest::Reader req : zemReader.getListMsg()) {

		Request newReq;

		newReq.key = string(req.getKey());
		newReq.val = string(req.getVal());
		newReq.opCode = string(req.getOpcode());

		reqList.push_back(newReq);

	}

	return reqList;
}

int concatBuf(void* srcBuf, size_t srcLen, void* &dstBuf) {

	size_t len = srcLen;
	dstBuf = malloc(sizeof(size_t) + len);

	memcpy(dstBuf, &len, sizeof(size_t));

	memcpy(((char*)dstBuf + sizeof(size_t)), srcBuf, len);

	return 0;
}

size_t splitBuf(void* srcBuf, void* &dstBuf) {

	size_t capnLen = -1;

	memcpy(&capnLen, srcBuf, sizeof(size_t));

	if (capnLen > 0) {
		dstBuf = calloc(capnLen+1, sizeof(byte));
		memcpy(dstBuf,((char*)srcBuf + sizeof(size_t)), capnLen);
		memset(((char*)dstBuf+capnLen), '\0', 1);
	}

	return capnLen;
}

