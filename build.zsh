# build.zsh: creates the executables for this toy language.
# DrkWithT

debug_option='y';
debug_flag=1;

# prompt for build mode
read -p "Do debug build (y/n)? " debug_option

if [[ $debug_option == "y" ]]
then
    debug_flag=1
else
    debug_flag=0
fi

# clean old execs and do custom build: debug or optimized.
make clean_execs && make DEBUG_BUILD=$debug_flag all && echo -e "\033[0;32mBuild succeeded!\033[0m" || echo -e "\033[0;31mBuild failed!\033[0m"
