import numpy as np
import matplotlib.pyplot as plt

qf43 = [29.6488, 28.8017, 29.4792, 30.9842]
bndm = [7.059, 7.03139, 8.47803, 7.16593]

y = np.arange(4)
# y = [8, 16, 32, 64]

plt.plot(y, qf43, label="qf43", linewidth=4)
plt.plot(y, bndm, label="bndm", linewidth=4)
plt.legend(loc=2, prop={'size': 15})
plt.grid(True, linestyle=':')
plt.xticks(y, ('8', '16', '32', '64'), fontsize=16)
plt.yticks(fontsize=16)
plt.xlabel('Pattern Length', fontsize=17)
plt.ylabel('Time (s)', rotation=0, fontsize=15)
plt.show()

qf43_trim = [33.0342, 34.2925, 42.9897, 33.6567]
bndm_trim = [13.3473, 12.99992, 13.932, 13.854]

plt.plot(y, qf43_trim, label="qf43 w/ quality trim.", linewidth=4)
plt.plot(y, bndm_trim, label="bndm w/ quality trim.", linewidth=4)
plt.legend(loc=2, prop={'size': 15})
plt.grid(True, linestyle=':')
plt.xticks(y, ('8', '16', '32', '64'), fontsize=16)
plt.yticks(fontsize=16)
plt.xlabel('Pattern Length', fontsize=17)
plt.ylabel('Time (s)', rotation=0, fontsize=15)
plt.show()
