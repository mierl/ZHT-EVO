// Generated by Cap'n Proto compiler, DO NOT EDIT
// source: zht_evo.capnp

#ifndef CAPNP_INCLUDED_da8cc01ab73b69b8_
#define CAPNP_INCLUDED_da8cc01ab73b69b8_

#include <capnp/generated-header-support.h>

#if CAPNP_VERSION != 5003
#error "Version mismatch between generated code and library headers.  You must use the same version of the Cap'n Proto compiler and library."
#endif


namespace capnp {
namespace schemas {

CAPNP_DECLARE_SCHEMA(a162247997eba97b);
CAPNP_DECLARE_SCHEMA(80867c875d56d932);

}  // namespace schemas
}  // namespace capnp

namespace capnp {
namespace schema {

struct ZEMessage {
  ZEMessage() = delete;

  class Reader;
  class Builder;
  class Pipeline;

  struct _capnpPrivate {
    CAPNP_DECLARE_STRUCT_HEADER(a162247997eba97b, 1, 1)
    #if !CAPNP_LITE
    static constexpr ::capnp::_::RawBrandedSchema const* brand = &schema->defaultBrand;
    #endif  // !CAPNP_LITE
  };
};

struct KVRequest {
  KVRequest() = delete;

  class Reader;
  class Builder;
  class Pipeline;

  struct _capnpPrivate {
    CAPNP_DECLARE_STRUCT_HEADER(80867c875d56d932, 0, 3)
    #if !CAPNP_LITE
    static constexpr ::capnp::_::RawBrandedSchema const* brand = &schema->defaultBrand;
    #endif  // !CAPNP_LITE
  };
};

// =======================================================================================

class ZEMessage::Reader {
public:
  typedef ZEMessage Reads;

  Reader() = default;
  inline explicit Reader(::capnp::_::StructReader base): _reader(base) {}

  inline ::capnp::MessageSize totalSize() const {
    return _reader.totalSize().asPublic();
  }

#if !CAPNP_LITE
  inline ::kj::StringTree toString() const {
    return ::capnp::_::structString(_reader, *_capnpPrivate::brand);
  }
#endif  // !CAPNP_LITE

  inline  ::uint16_t getNRequest() const;

  inline bool hasListMsg() const;
  inline  ::capnp::List< ::capnp::schema::KVRequest>::Reader getListMsg() const;

private:
  ::capnp::_::StructReader _reader;
  template <typename, ::capnp::Kind>
  friend struct ::capnp::ToDynamic_;
  template <typename, ::capnp::Kind>
  friend struct ::capnp::_::PointerHelpers;
  template <typename, ::capnp::Kind>
  friend struct ::capnp::List;
  friend class ::capnp::MessageBuilder;
  friend class ::capnp::Orphanage;
};

class ZEMessage::Builder {
public:
  typedef ZEMessage Builds;

  Builder() = delete;  // Deleted to discourage incorrect usage.
                       // You can explicitly initialize to nullptr instead.
  inline Builder(decltype(nullptr)) {}
  inline explicit Builder(::capnp::_::StructBuilder base): _builder(base) {}
  inline operator Reader() const { return Reader(_builder.asReader()); }
  inline Reader asReader() const { return *this; }

  inline ::capnp::MessageSize totalSize() const { return asReader().totalSize(); }
#if !CAPNP_LITE
  inline ::kj::StringTree toString() const { return asReader().toString(); }
#endif  // !CAPNP_LITE

  inline  ::uint16_t getNRequest();
  inline void setNRequest( ::uint16_t value);

  inline bool hasListMsg();
  inline  ::capnp::List< ::capnp::schema::KVRequest>::Builder getListMsg();
  inline void setListMsg( ::capnp::List< ::capnp::schema::KVRequest>::Reader value);
  inline  ::capnp::List< ::capnp::schema::KVRequest>::Builder initListMsg(unsigned int size);
  inline void adoptListMsg(::capnp::Orphan< ::capnp::List< ::capnp::schema::KVRequest>>&& value);
  inline ::capnp::Orphan< ::capnp::List< ::capnp::schema::KVRequest>> disownListMsg();

private:
  ::capnp::_::StructBuilder _builder;
  template <typename, ::capnp::Kind>
  friend struct ::capnp::ToDynamic_;
  friend class ::capnp::Orphanage;
  template <typename, ::capnp::Kind>
  friend struct ::capnp::_::PointerHelpers;
};

#if !CAPNP_LITE
class ZEMessage::Pipeline {
public:
  typedef ZEMessage Pipelines;

  inline Pipeline(decltype(nullptr)): _typeless(nullptr) {}
  inline explicit Pipeline(::capnp::AnyPointer::Pipeline&& typeless)
      : _typeless(kj::mv(typeless)) {}

private:
  ::capnp::AnyPointer::Pipeline _typeless;
  friend class ::capnp::PipelineHook;
  template <typename, ::capnp::Kind>
  friend struct ::capnp::ToDynamic_;
};
#endif  // !CAPNP_LITE

class KVRequest::Reader {
public:
  typedef KVRequest Reads;

  Reader() = default;
  inline explicit Reader(::capnp::_::StructReader base): _reader(base) {}

  inline ::capnp::MessageSize totalSize() const {
    return _reader.totalSize().asPublic();
  }

#if !CAPNP_LITE
  inline ::kj::StringTree toString() const {
    return ::capnp::_::structString(_reader, *_capnpPrivate::brand);
  }
#endif  // !CAPNP_LITE

  inline bool hasKey() const;
  inline  ::capnp::Text::Reader getKey() const;

  inline bool hasVal() const;
  inline  ::capnp::Text::Reader getVal() const;

  inline bool hasOpcode() const;
  inline  ::capnp::Text::Reader getOpcode() const;

private:
  ::capnp::_::StructReader _reader;
  template <typename, ::capnp::Kind>
  friend struct ::capnp::ToDynamic_;
  template <typename, ::capnp::Kind>
  friend struct ::capnp::_::PointerHelpers;
  template <typename, ::capnp::Kind>
  friend struct ::capnp::List;
  friend class ::capnp::MessageBuilder;
  friend class ::capnp::Orphanage;
};

class KVRequest::Builder {
public:
  typedef KVRequest Builds;

  Builder() = delete;  // Deleted to discourage incorrect usage.
                       // You can explicitly initialize to nullptr instead.
  inline Builder(decltype(nullptr)) {}
  inline explicit Builder(::capnp::_::StructBuilder base): _builder(base) {}
  inline operator Reader() const { return Reader(_builder.asReader()); }
  inline Reader asReader() const { return *this; }

  inline ::capnp::MessageSize totalSize() const { return asReader().totalSize(); }
#if !CAPNP_LITE
  inline ::kj::StringTree toString() const { return asReader().toString(); }
#endif  // !CAPNP_LITE

  inline bool hasKey();
  inline  ::capnp::Text::Builder getKey();
  inline void setKey( ::capnp::Text::Reader value);
  inline  ::capnp::Text::Builder initKey(unsigned int size);
  inline void adoptKey(::capnp::Orphan< ::capnp::Text>&& value);
  inline ::capnp::Orphan< ::capnp::Text> disownKey();

  inline bool hasVal();
  inline  ::capnp::Text::Builder getVal();
  inline void setVal( ::capnp::Text::Reader value);
  inline  ::capnp::Text::Builder initVal(unsigned int size);
  inline void adoptVal(::capnp::Orphan< ::capnp::Text>&& value);
  inline ::capnp::Orphan< ::capnp::Text> disownVal();

  inline bool hasOpcode();
  inline  ::capnp::Text::Builder getOpcode();
  inline void setOpcode( ::capnp::Text::Reader value);
  inline  ::capnp::Text::Builder initOpcode(unsigned int size);
  inline void adoptOpcode(::capnp::Orphan< ::capnp::Text>&& value);
  inline ::capnp::Orphan< ::capnp::Text> disownOpcode();

private:
  ::capnp::_::StructBuilder _builder;
  template <typename, ::capnp::Kind>
  friend struct ::capnp::ToDynamic_;
  friend class ::capnp::Orphanage;
  template <typename, ::capnp::Kind>
  friend struct ::capnp::_::PointerHelpers;
};

#if !CAPNP_LITE
class KVRequest::Pipeline {
public:
  typedef KVRequest Pipelines;

  inline Pipeline(decltype(nullptr)): _typeless(nullptr) {}
  inline explicit Pipeline(::capnp::AnyPointer::Pipeline&& typeless)
      : _typeless(kj::mv(typeless)) {}

private:
  ::capnp::AnyPointer::Pipeline _typeless;
  friend class ::capnp::PipelineHook;
  template <typename, ::capnp::Kind>
  friend struct ::capnp::ToDynamic_;
};
#endif  // !CAPNP_LITE

// =======================================================================================

inline  ::uint16_t ZEMessage::Reader::getNRequest() const {
  return _reader.getDataField< ::uint16_t>(
      0 * ::capnp::ELEMENTS);
}

inline  ::uint16_t ZEMessage::Builder::getNRequest() {
  return _builder.getDataField< ::uint16_t>(
      0 * ::capnp::ELEMENTS);
}
inline void ZEMessage::Builder::setNRequest( ::uint16_t value) {
  _builder.setDataField< ::uint16_t>(
      0 * ::capnp::ELEMENTS, value);
}

inline bool ZEMessage::Reader::hasListMsg() const {
  return !_reader.getPointerField(0 * ::capnp::POINTERS).isNull();
}
inline bool ZEMessage::Builder::hasListMsg() {
  return !_builder.getPointerField(0 * ::capnp::POINTERS).isNull();
}
inline  ::capnp::List< ::capnp::schema::KVRequest>::Reader ZEMessage::Reader::getListMsg() const {
  return ::capnp::_::PointerHelpers< ::capnp::List< ::capnp::schema::KVRequest>>::get(
      _reader.getPointerField(0 * ::capnp::POINTERS));
}
inline  ::capnp::List< ::capnp::schema::KVRequest>::Builder ZEMessage::Builder::getListMsg() {
  return ::capnp::_::PointerHelpers< ::capnp::List< ::capnp::schema::KVRequest>>::get(
      _builder.getPointerField(0 * ::capnp::POINTERS));
}
inline void ZEMessage::Builder::setListMsg( ::capnp::List< ::capnp::schema::KVRequest>::Reader value) {
  ::capnp::_::PointerHelpers< ::capnp::List< ::capnp::schema::KVRequest>>::set(
      _builder.getPointerField(0 * ::capnp::POINTERS), value);
}
inline  ::capnp::List< ::capnp::schema::KVRequest>::Builder ZEMessage::Builder::initListMsg(unsigned int size) {
  return ::capnp::_::PointerHelpers< ::capnp::List< ::capnp::schema::KVRequest>>::init(
      _builder.getPointerField(0 * ::capnp::POINTERS), size);
}
inline void ZEMessage::Builder::adoptListMsg(
    ::capnp::Orphan< ::capnp::List< ::capnp::schema::KVRequest>>&& value) {
  ::capnp::_::PointerHelpers< ::capnp::List< ::capnp::schema::KVRequest>>::adopt(
      _builder.getPointerField(0 * ::capnp::POINTERS), kj::mv(value));
}
inline ::capnp::Orphan< ::capnp::List< ::capnp::schema::KVRequest>> ZEMessage::Builder::disownListMsg() {
  return ::capnp::_::PointerHelpers< ::capnp::List< ::capnp::schema::KVRequest>>::disown(
      _builder.getPointerField(0 * ::capnp::POINTERS));
}

inline bool KVRequest::Reader::hasKey() const {
  return !_reader.getPointerField(0 * ::capnp::POINTERS).isNull();
}
inline bool KVRequest::Builder::hasKey() {
  return !_builder.getPointerField(0 * ::capnp::POINTERS).isNull();
}
inline  ::capnp::Text::Reader KVRequest::Reader::getKey() const {
  return ::capnp::_::PointerHelpers< ::capnp::Text>::get(
      _reader.getPointerField(0 * ::capnp::POINTERS));
}
inline  ::capnp::Text::Builder KVRequest::Builder::getKey() {
  return ::capnp::_::PointerHelpers< ::capnp::Text>::get(
      _builder.getPointerField(0 * ::capnp::POINTERS));
}
inline void KVRequest::Builder::setKey( ::capnp::Text::Reader value) {
  ::capnp::_::PointerHelpers< ::capnp::Text>::set(
      _builder.getPointerField(0 * ::capnp::POINTERS), value);
}
inline  ::capnp::Text::Builder KVRequest::Builder::initKey(unsigned int size) {
  return ::capnp::_::PointerHelpers< ::capnp::Text>::init(
      _builder.getPointerField(0 * ::capnp::POINTERS), size);
}
inline void KVRequest::Builder::adoptKey(
    ::capnp::Orphan< ::capnp::Text>&& value) {
  ::capnp::_::PointerHelpers< ::capnp::Text>::adopt(
      _builder.getPointerField(0 * ::capnp::POINTERS), kj::mv(value));
}
inline ::capnp::Orphan< ::capnp::Text> KVRequest::Builder::disownKey() {
  return ::capnp::_::PointerHelpers< ::capnp::Text>::disown(
      _builder.getPointerField(0 * ::capnp::POINTERS));
}

inline bool KVRequest::Reader::hasVal() const {
  return !_reader.getPointerField(1 * ::capnp::POINTERS).isNull();
}
inline bool KVRequest::Builder::hasVal() {
  return !_builder.getPointerField(1 * ::capnp::POINTERS).isNull();
}
inline  ::capnp::Text::Reader KVRequest::Reader::getVal() const {
  return ::capnp::_::PointerHelpers< ::capnp::Text>::get(
      _reader.getPointerField(1 * ::capnp::POINTERS));
}
inline  ::capnp::Text::Builder KVRequest::Builder::getVal() {
  return ::capnp::_::PointerHelpers< ::capnp::Text>::get(
      _builder.getPointerField(1 * ::capnp::POINTERS));
}
inline void KVRequest::Builder::setVal( ::capnp::Text::Reader value) {
  ::capnp::_::PointerHelpers< ::capnp::Text>::set(
      _builder.getPointerField(1 * ::capnp::POINTERS), value);
}
inline  ::capnp::Text::Builder KVRequest::Builder::initVal(unsigned int size) {
  return ::capnp::_::PointerHelpers< ::capnp::Text>::init(
      _builder.getPointerField(1 * ::capnp::POINTERS), size);
}
inline void KVRequest::Builder::adoptVal(
    ::capnp::Orphan< ::capnp::Text>&& value) {
  ::capnp::_::PointerHelpers< ::capnp::Text>::adopt(
      _builder.getPointerField(1 * ::capnp::POINTERS), kj::mv(value));
}
inline ::capnp::Orphan< ::capnp::Text> KVRequest::Builder::disownVal() {
  return ::capnp::_::PointerHelpers< ::capnp::Text>::disown(
      _builder.getPointerField(1 * ::capnp::POINTERS));
}

inline bool KVRequest::Reader::hasOpcode() const {
  return !_reader.getPointerField(2 * ::capnp::POINTERS).isNull();
}
inline bool KVRequest::Builder::hasOpcode() {
  return !_builder.getPointerField(2 * ::capnp::POINTERS).isNull();
}
inline  ::capnp::Text::Reader KVRequest::Reader::getOpcode() const {
  return ::capnp::_::PointerHelpers< ::capnp::Text>::get(
      _reader.getPointerField(2 * ::capnp::POINTERS));
}
inline  ::capnp::Text::Builder KVRequest::Builder::getOpcode() {
  return ::capnp::_::PointerHelpers< ::capnp::Text>::get(
      _builder.getPointerField(2 * ::capnp::POINTERS));
}
inline void KVRequest::Builder::setOpcode( ::capnp::Text::Reader value) {
  ::capnp::_::PointerHelpers< ::capnp::Text>::set(
      _builder.getPointerField(2 * ::capnp::POINTERS), value);
}
inline  ::capnp::Text::Builder KVRequest::Builder::initOpcode(unsigned int size) {
  return ::capnp::_::PointerHelpers< ::capnp::Text>::init(
      _builder.getPointerField(2 * ::capnp::POINTERS), size);
}
inline void KVRequest::Builder::adoptOpcode(
    ::capnp::Orphan< ::capnp::Text>&& value) {
  ::capnp::_::PointerHelpers< ::capnp::Text>::adopt(
      _builder.getPointerField(2 * ::capnp::POINTERS), kj::mv(value));
}
inline ::capnp::Orphan< ::capnp::Text> KVRequest::Builder::disownOpcode() {
  return ::capnp::_::PointerHelpers< ::capnp::Text>::disown(
      _builder.getPointerField(2 * ::capnp::POINTERS));
}

}  // namespace
}  // namespace

#endif  // CAPNP_INCLUDED_da8cc01ab73b69b8_
