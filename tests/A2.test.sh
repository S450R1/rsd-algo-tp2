#!/bin/bash
sizes=(100000 200000 400000 600000 800000 1000000 1200000 1400000 1600000 1800000)

for n in "${sizes[@]}"; do
  echo "=== A2: n=$n (best case) ==="
  # best case for sequential sorted: x = first element = 1
  ( printf "%d\n" "$n"
    seq 1 "$n"
    printf "%d\n" 1 ) | ./A2

  echo ""
  echo "=== A2: n=$n (worst case) ==="
  # worst case: x not present (greater than all) = n+1
  ( printf "%d\n" "$n"
    seq 1 "$n"
    printf "%d\n" $((n+1)) ) | ./A2
  echo ""
done
