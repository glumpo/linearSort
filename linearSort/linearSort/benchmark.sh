make clean

if ! make benchmark; then
    echo "Failed on buil"
    exit 1
fi

sudo cpupower frequency-set --governor performance
./bench
sudo cpupower frequency-set --governor powersave

make clean
