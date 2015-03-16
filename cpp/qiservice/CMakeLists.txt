cmake_minimum_required(VERSION 2.8)
project(@ProjectName@)

find_package(qibuild)
find_package(qimodule)

include_directories(".")

set(PUBLIC_HEADERS
  @projectname@/api.hpp
  @projectname@/@projectname@.hpp
)
qi_install_header(KEEP_RELATIVE_PATHS ${PUBLIC_HEADERS})

set(SRCS
  src/@projectname@_proxy.cpp
  src/registration.cpp
)

qi_create_lib(@projectname@lib
  SRC
    ${PUBLIC_HEADERS}
    ${SRCS}
  DEPENDS
    QI
)
qi_stage_lib(@projectname@lib)

qi_create_module(@projectname@
  SRC
    src/@projectname@impl.cpp
    src/@projectname@impl.hpp
  DEPENDS
    QI
    @PROJECTNAME@LIB
)
