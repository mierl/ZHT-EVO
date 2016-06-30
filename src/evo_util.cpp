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
int zeMsgToCStr(capnp::MessageBuilder *msg, char* &to_capn_str, size_t &len) {
	int result = 0;
	kj::Array<capnp::word> words = messageToFlatArray(*msg);
	kj::ArrayPtr<kj::byte> bytes = words.asBytes();
	size_t nbytes = bytes.size();

	if ( NULL == to_capn_str) {
		len = nbytes;
		to_capn_str = (char*) malloc(nbytes);
	}

	if (nbytes <= len) { //error again?
		memcpy(to_capn_str, bytes.begin(), nbytes);
		//meltresult_success(result);
	} else {
		len = nbytes;
	}
	return result;
}

capnp::FlatArrayMessageReader* cstrToZEMsgReader(const char* from_capn_str,
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

ZEMessage::Reader getZEMsgReader(const char* from_capn_str, int capnStrSize) {

	capnp::FlatArrayMessageReader* data_in = cstrToZEMsgReader(from_capn_str,
			capnStrSize);
	ZEMessage::Reader zemReader = data_in->getRoot<ZEMessage>();
	return zemReader;
}
