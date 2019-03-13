file(GLOB HEADERS "include/beowulf/schema/*.hpp")
add_library( beowulf_schema schema.cpp ${HEADERS} )
target_link_libraries( beowulf_schema fc )
target_include_directories( beowulf_schema PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )

install( TARGETS
   beowulf_schema

   RUNTIME DESTINATION bin
   LIBRARY DESTINATION lib
   ARCHIVE DESTINATION lib
)
install( FILES ${HEADERS} DESTINATION "include/beowulf/schema" )
