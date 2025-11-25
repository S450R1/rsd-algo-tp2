#!/bin/bash
sizes=(100000 200000 400000 600000 800000 1000000 1200000 1400000 1600000 1800000)

for n in "${sizes[@]}"; do
  echo "=== A3: n=$n (best case) ==="
  # best case for binary search: choose x = arr[mid] where mid = (n-1)/2 -> value = mid+1
  mid=$(( (n-1)/2 ))
  best_x=$(( mid + 1 ))
  ( printf "%d\n" "$n"
    seq 1 "$n"
    printf "%d\n" "$best_x" ) | ./A3
  
  echo ""
  echo "=== A3: n=$n (worst case) ==="
  # worst case: x not present (greater than all) = n+1
  ( printf "%d\n" "$n"
    seq 1 "$n"
    printf "%d\n" $((n+1)) ) | ./A3
  echo ""
done
