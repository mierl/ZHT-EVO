/*
 * evo_util.h
 *
 *  Created on: Jun 27, 2016
 *      Author: Tony
 */
#include <iostream>

#include <capnp/message.h>
#include <capnp/serialize.h>
#include <capnp/serialize-packed.h>
#include <capnp/schema.h>
#include <capnp/generated-header-support.h>
#include "zht_evo.capnp.h"

using namespace capnp;
using namespace schema;
using namespace std;

int zeMsgToCStr(capnp::MessageBuilder *msg, char* &to_capn_str, size_t &len);
ZEMessage::Reader getZEMsgReader(const char* from_buf, int capnStrSize);
