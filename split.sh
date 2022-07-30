tail -n +2 input.csv | split -l 4 - split_
for file in split_*
do
    head -n 1 input.csv > tmp_file
    cat "$file" >> tmp_file
    mv -f tmp_file "$file"
done