file(GLOB HEADERS "include/beowulf/private_message/*.hpp")

add_library( beowulf_private_message
             private_message_plugin.cpp
           )

target_link_libraries( beowulf_private_message beowulf_chain beowulf_protocol beowulf_app )
target_include_directories( beowulf_private_message
                            PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )

install( TARGETS
   beowulf_private_message

   RUNTIME DESTINATION bin
   LIBRARY DESTINATION lib
   ARCHIVE DESTINATION lib
)
