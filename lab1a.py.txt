import matplotlib.pyplot as plt
n_values = [1000, 5000, 10000, 20000, 50000, 100000]
time_values=[0.000009, 0.000015 , 0.000035, 0.000036, 0.000049, 0.000212] # in seconds
plt.plot(n_values, time_values, marker='o')
plt.title("Linear Search: Time vs Number of Elements")
plt.xlabel("Number of Elements (n)")
plt.ylabel("Time Taken (seconds)")
plt.grid(True)
plt.show()