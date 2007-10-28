#ifndef CHANNELMANAGER_HXX
#define CHANNELMANAGER_HXX

#include <asio.hpp>

#include "RemotePeer.hxx"

namespace reTurn {


class ChannelManager
{
public:
   explicit ChannelManager();
   ~ChannelManager();

   RemotePeer* createRemotePeer(const StunTuple& peerTuple, unsigned char clientToServerChannel, unsigned char serverToClientChannel);
   void addRemotePeerServerToClientChannelLookup(RemotePeer* remotePeer);
   void addRemotePeerClientToServerChannelLookup(RemotePeer* remotePeer);

   RemotePeer* findRemotePeerByServerToClientChannel(unsigned char channelNumber);
   RemotePeer* findRemotePeerByClientToServerChannel(unsigned char channelNumber);
   RemotePeer* findRemotePeerByPeerAddress(const StunTuple& peerAddress);

   unsigned char getNextChannelNumber() { return mNextChannelNumber++; }

private:
   typedef std::map<unsigned char,RemotePeer*> ChannelRemotePeerMap;
   typedef std::map<StunTuple,RemotePeer*> TupleRemotePeerMap;
   ChannelRemotePeerMap mClientToServerChannelRemotePeerMap;
   ChannelRemotePeerMap mServerToClientChannelRemotePeerMap;
   TupleRemotePeerMap mTupleRemotePeerMap;

   unsigned char mNextChannelNumber;
};

} 

#endif


/* ====================================================================

 Original contribution Copyright (C) 2007 Plantronics, Inc.
 Provided under the terms of the Vovida Software License, Version 2.0.

 The Vovida Software License, Version 2.0 
 
 Redistribution and use in source and binary forms, with or without
 modification, are permitted provided that the following conditions
 are met:
 
 1. Redistributions of source code must retain the above copyright
    notice, this list of conditions and the following disclaimer.
 
 2. Redistributions in binary form must reproduce the above copyright
    notice, this list of conditions and the following disclaimer in
    the documentation and/or other materials provided with the
    distribution. 
 
 THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESSED OR IMPLIED
 WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, TITLE AND
 NON-INFRINGEMENT ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT
 OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT DAMAGES
 IN EXCESS OF $1,000, NOR FOR ANY INDIRECT, INCIDENTAL, SPECIAL,
 EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
 OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE
 USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH
 DAMAGE.

 ==================================================================== */

