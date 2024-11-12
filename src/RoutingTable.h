#ifndef ROUTINGTABLE_H
#define ROUTINGTABLE_H
#include "RouterTypes.h"

#include <string>
#include <filesystem>
#include <unordered_map>

/**
 * @struct RoutingEntry
 * @brief Represents a routing entry in the routing table.
 *
 * This struct contains the destination, gateway, mask, and interface
 * information for a routing entry.
 */
struct RoutingEntry
{
    uint32_t dest;      /**< The destination IP address for the routing entry. */
    uint32_t gateway;   /**< The gateway IP address for the routing entry. */
    uint32_t mask;      /**< The subnet mask for the routing entry. */
    std::string iface;  /**< The interface name associated with this route. */
};

/**
 * @struct RoutingInterface
 * @brief Represents a network interface in the routing table.
 *
 * This struct contains the name, MAC address, and IP address for a network interface.
 */
struct RoutingInterface
{
    std::string name; /**< The name of the network interface (e.g., eth0). */
    mac_addr mac;     /**< The MAC address of the network interface. */
    ip_addr ip;       /**< The IP address of the network interface. */
};

/**
 * @class RoutingTable
 * @brief Manages the routing table and network interfaces.
 *
 * This class provides methods for managing routing entries and interfaces,
 * such as retrieving a routing entry for a specific IP address or setting
 * the MAC and IP addresses for a given interface.
 */
class RoutingTable {
public:
    /**
     * @brief Constructs a RoutingTable object from a given file path.
     * @param routingTablePath The path to the file containing routing table entries.
     */
    explicit RoutingTable(const std::filesystem::path& routingTablePath);

    /**
     * @brief Retrieves the routing entry for a specified IP address using longest prefix matching.
     * @param ip The IP address to find a route for.
     * @return The routing entry associated with the specified IP address.
     */
    RoutingEntry getRoutingEntry(ip_addr ip);

    /**
     * @brief Retrieves the routing interface for a specified interface name.
     * @param iface The name of the network interface.
     * @return The routing interface associated with the specified name.
     */
    RoutingInterface getRoutingInterface(const std::string& iface);

    /**
     * @brief Sets the MAC and IP address for a specified network interface.
     * @param iface The name of the network interface to set.
     * @param mac The MAC address to assign to the network interface.
     * @param ip The IP address to assign to the network interface.
     */
    void setRoutingInterface(const std::string& iface, const mac_addr& mac, const ip_addr& ip);

private:
    std::vector<RoutingEntry> routingEntries; /**< Collection of routing entries. */
    std::unordered_map<std::string, RoutingInterface> routingInterfaces; /**< Map of interface names to routing interfaces. */
};



#endif //ROUTINGTABLE_H
