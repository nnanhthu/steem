file(GLOB HEADERS "include/beowulf/plugins/auth_util/*.hpp")

add_library( beowulf_auth_util
             ${HEADERS}
             auth_util_plugin.cpp
             auth_util_api.cpp
           )

target_link_libraries( beowulf_auth_util beowulf_app beowulf_chain beowulf_protocol fc )
target_include_directories( beowulf_auth_util
                            PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )
