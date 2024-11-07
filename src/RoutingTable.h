#ifndef ROUTINGTABLE_H
#define ROUTINGTABLE_H
#include "RouterTypes.h"

#include <string>
#include <filesystem>
#include <unordered_map>

struct RoutingEntry
{
    uint32_t dest;
    uint32_t gateway;
    uint32_t mask;
    std::string iface;
};

struct RoutingInterface
{
    std::string name;
    mac_addr mac;
    ip_addr ip;
};

class RoutingTable {
public:
    explicit RoutingTable(const std::filesystem::path& routingTablePath);

    RoutingEntry getRoutingEntry(ip_addr ip);
    RoutingInterface getRoutingInterface(const std::string& iface);

    void setRoutingInterface(const std::string& iface, const mac_addr& mac, const ip_addr& ip);
private:
    std::vector<RoutingEntry> routingEntries;
    std::unordered_map<std::string, RoutingInterface> routingInterfaces;
};



#endif //ROUTINGTABLE_H
