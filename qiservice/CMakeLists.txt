cmake_minimum_required(VERSION 2.8)
project(@ProjectName@)

find_package(qibuild)
find_package(qimodule)

include_directories(".")

set(PUBLIC_HEADERS
  @projectname@/api.hpp
  @projectname@/@projectname@.hpp
)
qi_install_header(${PUBLIC_HEADERS})

set(PUBLIC_SRCS
  src/@projectname@_proxy.cpp
  src/registration.cpp
)

qi_create_lib(@projectname@lib
  SRC
    ${PUBLIC_HEADERS}
    ${PUBLIC_SRCS}
  DEPENDS
    QI
)
qi_stage_lib(@projectname@lib)

qi_create_module(@projectname@
  SRC
    ${PUBLIC_HEADERS}
    ${PUBLIC_SRCS}
    src/@projectname@impl.cpp
    src/@projectname@impl.hpp
  DEPENDS
    QI
    @PROJECTNAME@LIB
)
