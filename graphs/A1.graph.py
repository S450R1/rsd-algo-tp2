import os
import numpy as np
import matplotlib.pyplot as plt

N = [100000,200000,400000,600000,800000,1000000,1200000,1400000,1600000,1800000]
T = [0.000362,0.000549,0.001093,0.001484,0.001978,0.002480,0.002986,0.003481,0.003969,0.004465]

os.makedirs('static', exist_ok=True)

plt.figure(figsize=(8,5))
plt.plot(N, T, marker='o', linewidth=1)
plt.xlabel('N')
plt.ylabel('Time (seconds)')
plt.title('A1: Experimental T(N) - Worst case')
plt.grid(True, alpha=0.3)
plt.ticklabel_format(style='scientific', axis='x', scilimits=(0,0))

O_N = np.array(N) / N[0] * T[0]
plt.plot(N, O_N, marker='^', linewidth=1, linestyle='--')
plt.legend(['Experimental', 'Normalized O(N)'])
outfile = 'static/A1.graph.png'
plt.tight_layout()
plt.savefig(outfile, dpi=300, bbox_inches='tight')
