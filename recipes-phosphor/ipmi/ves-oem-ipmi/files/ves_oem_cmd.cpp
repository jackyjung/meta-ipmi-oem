#include <ipmid/api.hpp>
#include <ipmid/message.hpp>
#include <phosphor-logging/log.hpp>

using namespace phosphor::logging;

// OEM handler: netfn 0x3C, cmd 0x24
// Returns a fixed test value (0xAA) as the response.
static ipmi::RspType<uint8_t>
oemTestCommand(ipmi::Context::ptr ctx)
{
    // Log that we got called
    log<level::INFO>("OEM Test Command invoked, returning 0xAA");

    // Return completion code success + one byte payload: 0xAA
    uint8_t testValue = 0xAA;
    log<level::INFO>("Result returning 0xAA");
    return ipmi::responseSuccess(testValue);
}

// Register handler when plugin is loaded
void register_my_oem_cmd() __attribute__((constructor));
void register_my_oem_cmd()
{
    // IPMI v2.0, OEM netfn 0x3C, cmd 0x24
    // No request parameters, 1-byte response
    ipmi::registerHandler(
        ipmi::prioOemBase,
        0x3C,
        0x24,
        ipmi::Privilege::User,
        oemTestCommand);
}
