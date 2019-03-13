file(GLOB HEADERS "include/beowulf/account_statistics/*.hpp")

add_library( beowulf_account_statistics
             account_statistics_plugin.cpp
             account_statistics_api.cpp
           )

target_link_libraries( beowulf_account_statistics beowulf_chain beowulf_protocol beowulf_app )
target_include_directories( beowulf_account_statistics
                            PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )

install( TARGETS
   beowulf_account_statistics

   RUNTIME DESTINATION bin
   LIBRARY DESTINATION lib
   ARCHIVE DESTINATION lib
)