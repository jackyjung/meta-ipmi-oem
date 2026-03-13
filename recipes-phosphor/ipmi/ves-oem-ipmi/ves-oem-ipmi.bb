SUMMARY = "Ves OEM IPMI command plugin"
DESCRIPTION = "OEM IPMI command (netfn 0x3C, cmd 0x24) for OpenBMC"
LICENSE = "Apache-2.0"
LIC_FILES_CHKSUM = "file://LICENSE;md5=7c1899db70cd2fab31902ab14e2f6fa1"

SRC_URI = "file://ves_oem_cmd.cpp \
           file://CMakeLists.txt \
           file://LICENSE \
          "

S = "${WORKDIR}"

DEPENDS += "phosphor-ipmi-host sdbusplus phosphor-logging"

inherit pkgconfig cmake

FILES:${PN} += "${libdir}/ipmid-providers/libves_oem_cmd.so"
