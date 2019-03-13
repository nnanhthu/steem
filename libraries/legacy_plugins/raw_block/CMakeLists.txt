file(GLOB HEADERS "include/beowulf/plugins/raw_block/*.hpp")

add_library( beowulf_raw_block
             ${HEADERS}
             raw_block_plugin.cpp
             raw_block_api.cpp
           )

target_link_libraries( beowulf_raw_block beowulf_app beowulf_chain beowulf_protocol fc )
target_include_directories( beowulf_raw_block
                            PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )
