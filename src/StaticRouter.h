#ifndef STATICROUTER_H
#define STATICROUTER_H
#include <vector>

#include "ArpCache.h"


class StaticRouter {
public:
    StaticRouter(std::unique_ptr<ArpCache> arpCache, std::shared_ptr<RoutingTable> routingTable, std::shared_ptr<IPacketSender> packetSender);

    void handlePacket(std::vector<uint8_t> packet, std::string iface);

private:
    std::mutex mutex;

    std::shared_ptr<RoutingTable> routingTable;
    std::shared_ptr<IPacketSender> packetSender;

    std::unique_ptr<ArpCache> arpCache;
};



#endif //STATICROUTER_H
