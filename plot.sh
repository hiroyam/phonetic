cat << 'EOF' | gnuplot

set terminal pngcairo size 640,360 enhanced font 'DejaVuSansMono,8'

# set xrange [1:60000]
# set yrange [0:100]

set mytics 2
set grid mytics

set offsets 0.1, 0.1, 0.1, 0.1

# set xlabel ""
# set ylabel "accuracy"
# plot \
#     "aaaa" w l ls 8 t 'aaaa'
# plot \
#     "output" w p ls 8 t ''
# plot "< awk -F , '$3 == 1 ' train.csv" using 1:2 w p ls 8 ps 1 t '', \
#      "< awk -F , '$3 == -1' train.csv" using 1:2 w p ls 4 t '',  \
#      "< awk      '$3 == 1'  output"    using 1:2 w p ls 2 t '', \
#      "< awk      '$3 == -1' output"    using 1:2 w p ls 6 t ''
# set datafile separator ","

# plot "< awk      '$3 == 1'  output"                       using 1:2 w p ls 10 pt 1 ps 0.5 lw 1 t '', \
#      "< awk      '$3 == -1' output"                       using 1:2 w p ls 9  pt 1 ps 0.5 lw 1 t '', \
#      "< awk -F , '$3 == 1'  train.csv | sed -e 's/,/ /g'" using 1:2 w p ls 6 ps 1.5 t '', \
#      "< awk -F , '$3 == -1' train.csv | sed -e 's/,/ /g'" using 1:2 w p ls 8 ps 1.5 t ''

# plot "< awk '$3 == 1'  test2"  using 1:2 w p ls 10 pt 1 ps 0.5 lw 1 t '', \
#      "< awk '$3 == -1' test2"  using 1:2 w p ls 9  pt 1 ps 0.5 lw 1 t '', \
#      "< awk '$3 == 1'  output" using 1:2 w p ls 6 ps 1.5 t '', \
#      "< awk '$3 == -1' output" using 1:2 w p ls 8 ps 1.5 t ''

# plot "< awk '$3 == 0' output" using 1:2 w p ls 2  ps 1.5 lw 1 t 'a', \
#      "< awk '$3 == 1' output" using 1:2 w p ls 4  ps 1.5 lw 1 t 'i', \
#      "< awk '$3 == 2' output" using 1:2 w p ls 6  ps 1.5 lw 1 t 'u', \
#      "< awk '$3 == 3' output" using 1:2 w p ls 8  ps 1.5 lw 1 t 'e', \
#      "< awk '$3 == 4' output" using 1:2 w p ls 1  ps 1.5 lw 1 t 'o', \

plot "< awk '$3 == 0' output" using 1:2 w p ls 2  ps 1.5 lw 1 t 'yukari', \
     "< awk '$3 == 1' output" using 1:2 w p ls 4  ps 1.5 lw 1 t 'maki', \
     "< awk '$3 == 2' output" using 1:2 w p ls 6  ps 1.5 lw 1 t 'akane', \

EOF
