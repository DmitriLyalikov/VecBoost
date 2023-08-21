import matplotlib.pyplot as plt
import numpy as np
import math

cpu_fpconv = sorted([8871951, 5194639, 2957327, 4153359, 2768911, 1384463, 2457614, 1638414, 819214])
cpu_fpconv = cpu_fpconv[::-1]
hwacha_fpconv = sorted([155960, 103976, 51992, 73016, 48686, 24344, 43208, 28808, 14408])
hwacha_fpconv = hwacha_fpconv[::-1]
cpu_fd_to_nchw= sorted([5559580/4, 3706391/4, 1850760/4, 2605850/4, 1737237/4, 866950/4, 1543706/4, 1029141/4, 513286/4])
cpu_fd_to_nchw = cpu_fd_to_nchw[::-1]
cpu_fd_to_nchw = [math.ceil(num) for num in cpu_fd_to_nchw]

hwacha_fd_to_nchw = sorted([277253, 184837, 92421, 129797, 86533, 43269, 76805, 51205, 25605])
hwacha_fd_to_nchw = hwacha_fd_to_nchw[::-1]

cpu_total = []
if len(cpu_fpconv) == len(cpu_fd_to_nchw):
    for i in range(len(cpu_fpconv)):
        cpu_total.append(cpu_fpconv[i] + cpu_fd_to_nchw[i])

hwacha_total = []
if len(hwacha_fpconv) == len(hwacha_fd_to_nchw):
    for i in range(len(hwacha_fpconv)):
        hwacha_total.append(hwacha_fpconv[i] + hwacha_fd_to_nchw[i])
# x = [608**2 *3, 416**2 * 3, 320**2*3, 608**2 *2, 416**2 *2, 320**2*2,  608**2 *1, 416**2*1, 320**2*1 ]
x = ['608*3', '416*3', '320*3', '608*2', '416*2', '320*2', '608*1', '416*1', '320*1']
x_numeric = np.arange(len(x))
cpu_trend = np.polyfit(x_numeric, np.log(cpu_total), 1)
cpu_trendline = np.poly1d(cpu_trend)

hwacha_trend = np.polyfit(x_numeric, np.log(hwacha_total), 1)
hwacha_trendline = np.poly1d(hwacha_trend)

x = np.arange(len(cpu_fpconv))
bar_width = 0.35

plt.bar(x, cpu_total, width=bar_width, label='CPU', color='blue')
plt.bar(x + bar_width, hwacha_total, width=bar_width, label='Hwacha', color='green')

# Adding data labels to the bars with smaller font size
for i, v in enumerate(cpu_total):
    plt.text(i, v + 1, str(v), ha='center', va='bottom', fontweight='bold', fontsize=5, color='black')

for i, v in enumerate(hwacha_total):
    plt.text(i + bar_width + .05, v + 1, str(v), ha='center', va='bottom', fontweight='bold', fontsize=5, color='black')

plt.plot(x, np.exp(cpu_trendline(x_numeric)), color ='red')
plt.plot(x, np.exp(hwacha_trendline(x_numeric)), color ='green')
plt.xlabel('Image Size')
plt.ylabel('Execution Cycles')
plt.title('CPU vs. Hwacha YOLOv3 Conversion Layer Execution')
plt.xticks(x + bar_width / 2, ['608*3', '416*3', '320*3', '608*2', '416*2', '320*2', '608*1', '416*1', '320*1'])
plt.legend()
plt.tight_layout()
plt.show()
