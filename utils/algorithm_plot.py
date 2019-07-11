import numpy as np
import matplotlib.pyplot as plt

qf43 = [29.6488, 28.8017, 29.4792, 30.9842]
bndm = [7.059, 7.03139, 8.47803, 7.16593]

y = np.arange(4)
# y = [8, 16, 32, 64]

plt.plot(y, qf43, label="qf43")
plt.plot(y, bndm, label="bndm")
plt.legend()
plt.grid(True, linestyle=':')
plt.xticks(y, ('8', '16', '32', '64'))
plt.xlabel('Pattern Length')
plt.ylabel('Time (s)')
plt.show()

qf43_trim = [33.0342, 34.2925, 42.9897, 33.6567]
bndm_trim = [13.3473, 12.99992, 13.932, 13.854]

plt.plot(y, qf43_trim, label="qf43-trim")
plt.plot(y, bndm_trim, label="bndm-trim")
plt.legend()
plt.grid(True, linestyle=':')
plt.xticks(y, ('8', '16', '32', '64'))
plt.xlabel('Pattern Length')
plt.ylabel('Time (s)')
plt.show()
