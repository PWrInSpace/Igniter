# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/home/ewa/esp/esp-idf/components/bootloader/subproject"
  "/home/ewa/Desktop/rakiety/igniter/igniter/build/bootloader"
  "/home/ewa/Desktop/rakiety/igniter/igniter/build/bootloader-prefix"
  "/home/ewa/Desktop/rakiety/igniter/igniter/build/bootloader-prefix/tmp"
  "/home/ewa/Desktop/rakiety/igniter/igniter/build/bootloader-prefix/src/bootloader-stamp"
  "/home/ewa/Desktop/rakiety/igniter/igniter/build/bootloader-prefix/src"
  "/home/ewa/Desktop/rakiety/igniter/igniter/build/bootloader-prefix/src/bootloader-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/home/ewa/Desktop/rakiety/igniter/igniter/build/bootloader-prefix/src/bootloader-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/home/ewa/Desktop/rakiety/igniter/igniter/build/bootloader-prefix/src/bootloader-stamp${cfgdir}") # cfgdir has leading slash
endif()
