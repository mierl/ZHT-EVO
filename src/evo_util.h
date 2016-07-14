/*
 * evo_util.h
 *
 *  Created on: Jun 27, 2016
 *      Author: Tony
 */
#include <iostream>
#include <list>
#include <vector>
#include <capnp/message.h>
#include <capnp/serialize.h>
#include <capnp/serialize-packed.h>
#include <capnp/schema.h>
#include <capnp/generated-header-support.h>

#include "zht_evo.capnp.h"

using namespace capnp;
using namespace schema;
using namespace std;

struct Request{
	string key;
	string val;
	string opCode;
};

::capnp::MallocMessageBuilder* makeMsgPack(vector<Request> reqList);

int msgToBuff(capnp::MessageBuilder *msg, void* &to_capn_str, size_t &len);

ZEMessage::Reader getZEMsgReader(const void* from_buf, int capnStrSize);

vector<Request> extrReqVector(const void* from_capn_str, int capnStrSize);

int concatBuf(void* srcBuf, size_t srcLen, void* &dstBuf);

size_t splitBuf(void* srcBuf, void* &dstBuf);
