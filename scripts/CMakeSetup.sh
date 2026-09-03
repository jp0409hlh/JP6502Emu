# This script can be used if you want to compile to Linux and Windows at the same times

set -e 

function GenerateWindows(){
    echo "========= Setting up Windows Release Build Directory ========="
    if [[ ! -d ${build_dir}/Windows-Release ]]; then
        mkdir ${build_dir}/Windows-Release
    fi 

    cmake -S .. -B ${build_dir}/Windows-Release

    echo "========= Setting up Windows Debug Build Directory ========="
    if [[ ! -d ${build_dir}/Windows-Debug ]]; then
        mkdir ${build_dir}/Windows-Debug
    fi

    cmake -S .. -B ${build_dir}/Windows-Debug
}

function GenerateLinux(){
    echo "========= Setting up Linux Release Build Directory ========="
    if [[ ! -d ${build_dir}/Linux-Release ]]; then
        mkdir ${build_dir}/Linux-Release
    fi

    cmake -S .. -B ${build_dir}/Linux-Release

    echo "========= Setting up Linux Debug Build Directory ========="
    if [[ ! -d ${build_dir}/Linux-Debug ]]; then
        mkdir ${build_dir}/Linux-Debug
    fi

    cmake -S .. -B ${build_dir}/Linux-Debug
}

target_OS="$1"
build_dir="../build"

if [[ ! -d ${build_dir} ]]; then 
    mkdir ${build_dir}
fi 

if [[ $target_OS == "All" ]] ; then
    GenerateWindows
    GenerateLinux
elif [[ $target_OS == "Windows" ]] ; then
    GenerateWindows
elif [[ $target_OS == "Linux" ]] ; then 
    GenerateLinux 
else 
    echo "Argument error : Target OS name error"
    exit
fi 

wait 

echo "========= Setup Complete ========="

