import matplotlib.pyplot as plt
n_values = [100, 500, 1000, 5000, 10000, 50000,100000]
time_values=[0.000001,0.000005,0.000010, 0.000034, 0.000111, 0.001808,0.006747] # in seconds
plt.plot(n_values, time_values, marker='o')
plt.title("Insertion Sort: Time vs Number of Elements")
plt.xlabel("Number of Elements (n)")
plt.ylabel("Time Taken (seconds)")
plt.grid(True)
plt.show()