/**
 *   @file   SIEMUtil.hpp
 *   @brief  brief
 *
 *   detail
 *
 *   @internal www.captech.net.cn
 *   author:    Zhang peng
 *   mail:      zhangpeng@captech.net.cn,Developer.Zhang.Peng@gmail.com
 *   Created:   Nov 25, 2014
 *   Revision:  1.0.0
 *   Compiler:  gcc/g++
 *   Company:   Captech Co., Ltd.
 *   Copyright: Copyright (c) 2008, Captech Co., Ltd.
 *
 * =====================================================================================
 */

#ifndef SIEMUTIL_HPP_
#define SIEMUTIL_HPP_

#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/transport/TServerSocket.h>
#include <thrift/transport/TBufferTransports.h>

namespace SIEM
{
namespace Util
{

//thrift serialize
template<typename ThriftStruct>
bool static StringToThrift(const std::string& buff, \
        ThriftStruct* ts)
{
    using namespace apache::thrift::transport;
    using namespace apache::thrift::protocol;
    TMemoryBuffer* buffer = new TMemoryBuffer;
    buffer->write((const uint8_t*)buff.data(), buff.size());
    boost::shared_ptr<TTransport> trans(buffer);
    TBinaryProtocol protocol(trans);
    ts->read(&protocol);
    return true;
}

//thrift deserialize
template<typename ThriftStruct>
std::string static ThriftToString(const ThriftStruct& ts)
{
    using namespace apache::thrift::transport;
    using namespace apache::thrift::protocol;
    TMemoryBuffer* buffer = new TMemoryBuffer;
    boost::shared_ptr<TTransport> trans(buffer);
    TBinaryProtocol protocol(trans);
    ts.write(&protocol);
    uint8_t* buf;
    uint32_t size;
    buffer->getBuffer(&buf, &size);
    return std::string((char*)buf, (unsigned int)size);
}

} /* namespace Util */
} /* namespace SIEM */
#endif /* SIEMUTIL_HPP_ */
