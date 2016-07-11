@0xda8cc01ab73b69b8;

using Cxx = import "/capnp/c++.capnp";
$Cxx.namespace("capnp::schema");

struct ZEMessage {
	nRequest @0 :UInt16; # number of requests in this message
	listMsg @1 :List(KVRequest); # for batching and collection operations.

}

struct KVRequest {
	key @0 :Text;
	val @1 :Text;
	opcode @2 :Text; #operation code
}
