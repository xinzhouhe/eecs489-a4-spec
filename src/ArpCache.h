#ifndef ARPCACHE_H
#define ARPCACHE_H

#include <vector>
#include <array>
#include <chrono>
#include <list>
#include <set>
#include <unordered_map>
#include <thread>
#include <optional>
#include <mutex>
#include <chrono>

#include "IArpCache.h"
#include "IPacketSender.h"
#include "RouterTypes.h"
#include "RoutingTable.h"

class ArpCache : public IArpCache {
public:
    ArpCache(std::chrono::milliseconds timeout,
        std::shared_ptr<IPacketSender> packetSender, std::shared_ptr<RoutingTable> routingTable);
    ~ArpCache();

    void loop();

    void addEntry(uint32_t ip, const mac_addr& mac);

    std::optional<mac_addr> getEntry(uint32_t ip);

    void queuePacket(uint32_t ip, const Packet& packet, const std::string& iface);

private:
    void tick();

    std::chrono::milliseconds timeout;

    std::mutex mutex;
    std::unique_ptr<std::thread> thread;
    std::atomic<bool> shutdown = false;

    std::shared_ptr<IPacketSender> packetSender;
    std::shared_ptr<RoutingTable> routingTable;

    std::unordered_map<ip_addr, ArpEntry> entries;
    std::unordered_map<ip_addr, ArpRequest> requests;
};



#endif //ARPCACHE_H
