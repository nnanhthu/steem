file(GLOB HEADERS "include/beowulf/delayed_node/*.hpp")

add_library( beowulf_delayed_node
             delayed_node_plugin.cpp
           )

target_link_libraries( beowulf_delayed_node beowulf_chain beowulf_protocol beowulf_app )
target_include_directories( beowulf_delayed_node
                            PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )

if(MSVC)
  set_source_files_properties( delayed_node_plugin.cpp PROPERTIES COMPILE_FLAGS "/bigobj" )
endif(MSVC)

install( TARGETS
   beowulf_delayed_node

   RUNTIME DESTINATION bin
   LIBRARY DESTINATION lib
   ARCHIVE DESTINATION lib
)
