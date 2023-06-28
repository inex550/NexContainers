cmake_minimum_required(VERSION 3.12)

project(NexContainers)

set(CONTAINERS_INCLUDES
    includes/array/array.h
    includes/vector/vector.h
    includes/binary_tree/binary_tree.h
    includes/map/map.h
    includes/set/set.h
    includes/multiset/multiset.h
    includes/list/list.h
    includes/stack/stack.h
    includes/queue/queue.h
)

add_library(nex_containers
    ${CONTAINERS_INCLUDES}
)

target_include_directories(
    nex_containers INTERFACE includes
)