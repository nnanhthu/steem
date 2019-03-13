file(GLOB HEADERS "include/beowulf/blockchain_statistics/*.hpp")

add_library( beowulf_blockchain_statistics
             blockchain_statistics_plugin.cpp
             blockchain_statistics_api.cpp
           )

target_link_libraries( beowulf_blockchain_statistics beowulf_chain beowulf_protocol beowulf_app )
target_include_directories( beowulf_blockchain_statistics
                            PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )

install( TARGETS
   beowulf_blockchain_statistics

   RUNTIME DESTINATION bin
   LIBRARY DESTINATION lib
   ARCHIVE DESTINATION lib
)