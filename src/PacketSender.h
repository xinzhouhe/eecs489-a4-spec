#ifndef PACKETSENDER_H
#define PACKETSENDER_H

#include <string>

#include "RouterTypes.h"

class IPacketSender {
public:
    virtual ~IPacketSender() = default;

    virtual void sendPacket(Packet packet, const std::string& iface) = 0;
};

#endif //PACKETSENDER_H
