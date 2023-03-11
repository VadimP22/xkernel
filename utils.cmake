
macro(target_ffreestand target)
    target_compile_options(${target} PUBLIC "-ffreestanding")
    target_link_options(${target} PUBLIC "-nodefaultlibs")
    target_link_options(${target} PUBLIC "-nostartfiles")
    target_link_options(${target} PUBLIC "-static")
endmacro()


macro(target_cxx_disable_runtime target)
    target_compile_options(${target} PUBLIC "-fno-exceptions")
    target_compile_options(${target} PUBLIC "-fno-rtti")
    target_compile_options(${target} PUBLIC "-fno-pie")
    target_compile_options(${target} PUBLIC "-fno-stack-protector")
endmacro()


macro(target_linker_script target linker_script)
    target_link_options(${target} PUBLIC -T "${linker_script}")
endmacro()


macro(target_define_version target prefix major minor patch)
    target_compile_definitions(${target} PUBLIC "${prefix}_MAJOR=${major}")
    target_compile_definitions(${target} PUBLIC "${prefix}_MINOR=${minor}")
    target_compile_definitions(${target} PUBLIC "${prefix}_PATCH=${patch}")

    target_compile_definitions(${target} PUBLIC "${prefix}_MAJOR_STR=\"${major}\"")
    target_compile_definitions(${target} PUBLIC "${prefix}_MINOR_STR=\"${minor}\"")
    target_compile_definitions(${target} PUBLIC "${prefix}_PATCH_STR=\"${patch}\"")

    # check if have 6-th argument which represents build in semver 2.0.0
    if(${ARGC} MATCHES 6)
        target_compile_definitions(${target} PUBLIC "${prefix}_FULL_STR=\"${major}.${minor}.${patch}-${ARGV5}\"")
        target_compile_definitions(${target} PUBLIC "${prefix}_BUILD=${ARGV5}")
        target_compile_definitions(${target} PUBLIC "${prefix}_BUILD_STR=\"${ARGV5}\"")
    else()
        target_compile_definitions(${target} PUBLIC "${prefix}_FULL_STR=\"${major}.${minor}.${patch}\"")
        target_compile_definitions(${target} PUBLIC "${prefix}_BUILD=0")
        target_compile_definitions(${target} PUBLIC "${prefix}_BUILD_STR=\"\"")
    endif()
endmacro()


macro(target_config_bool target option_name state)
    if(${ARGC} MATCHES 4)
        set(${option_name} ${state} CACHE BOOL ${ARGV3})
    else()
        set(${option_name} ${state} CACHE BOOL "")
    endif()

    if($CACHE{${option_name}})
        target_compile_definitions(${target} PUBLIC "CONFIG_${option_name}")
        target_compile_definitions(${target} PUBLIC "CONFIG_${option_name}_ON=true")
        target_compile_definitions(${target} PUBLIC "CONFIG_${option_name}_OFF=false")
        target_compile_definitions(${target} PUBLIC "CONFIG_${option_name}_VAL=1")
    else()
        target_compile_definitions(${target} PUBLIC "CONFIG_${option_name}_ON=false")
        target_compile_definitions(${target} PUBLIC "CONFIG_${option_name}_OFF=true")
        target_compile_definitions(${target} PUBLIC "CONFIG_${option_name}_VAL=0")
    endif()
endmacro()