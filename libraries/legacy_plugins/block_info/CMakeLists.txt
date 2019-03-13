file(GLOB HEADERS "include/beowulf/plugins/block_info/*.hpp")

add_library( beowulf_block_info
             ${HEADERS}
             block_info_plugin.cpp
             block_info_api.cpp
           )

target_link_libraries( beowulf_block_info beowulf_app beowulf_chain beowulf_protocol fc )
target_include_directories( beowulf_block_info
                            PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )
