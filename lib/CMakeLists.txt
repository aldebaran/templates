cmake_minimum_required(VERSION 2.8)
project(@ProjectName@)
find_package(qibuild)
qi_sanitize_compile_flags(HIDDEN_SYMBOLS)

include_directories(".")

set(@PROJECT_NAME@_PUBLIC_HEADERS
  @project_name@/@project_name@.hpp
)

set(@PROJECT_NAME@_SOURCES
  src/@project_name@.cpp
)

qi_create_lib(@project_name@
  ${@PROJECT_NAME@_SOURCES}
)

qi_use_lib(@project_name@ QI)
qi_stage_lib(@project_name@)

qi_install_header(${@PROJECT_NAME@_PUBLIC_HEADERS} KEEP_RELATIVE_PATHS)

add_subdirectory(test)
