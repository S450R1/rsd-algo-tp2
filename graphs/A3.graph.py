import os
import numpy as np
import matplotlib.pyplot as plt

N = [100000,200000,400000,600000,800000,1000000,1200000,1400000,1600000,1800000]
T = [0.000004,0.000003,0.000002,0.000001,0.000002,0.000002,0.000002,0.000002,0.000002,0.000002]

os.makedirs('static', exist_ok=True)

plt.figure(figsize=(8,5))
plt.plot(N, T, marker='o', linewidth=1)
plt.xlabel('N')
plt.ylabel('Time (seconds)')
plt.title('A3: Experimental T(N) - Worst case')
plt.grid(True, alpha=0.3)
plt.ticklabel_format(style='scientific', axis='x', scilimits=(0,0))

O_log = np.log2(N) / np.log2(N[0]) * T[0]
plt.plot(N, O_log, marker='^', linewidth=1, linestyle='--')
plt.legend(['Experimental', 'Normalized O(log n)'])
outfile = 'static/A3.graph.png'
plt.tight_layout()
plt.savefig(outfile, dpi=300, bbox_inches='tight')
