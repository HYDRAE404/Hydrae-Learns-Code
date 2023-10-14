import tkinter as tk

default = ("Helvetica", 21)
height = 0
weight = 0

def get_weight(event):
    global weight
    weight = float(entry1.get())

def get_height(event):
    global height
    height = float(entry2.get())

def bmi():
    bmi = weight / (height*height)
    result.config(text=f"BMI: {bmi:.02f}", background="#544C4A")

root = tk.Tk()
root.title("BMI Calculator")
root.geometry("512x230")
root.configure(background="#222021")
root.resizable(False, False)

frame = tk.Frame(root, background="#363636")
frame.pack(padx=10, pady=10, anchor="center")

h_label = tk.Label(frame, text="Weight (kg): ", font=default, background="#363636", foreground="white")
h_label.grid(row=0, column=0)

entry1 = tk.Entry(frame, font=default, background="#363636", foreground="white")
entry1.config(width=20)
entry1.grid(row=0, column=1)

entry1.bind("<Return>", get_weight)

w_label = tk.Label(frame, text="Height (m): ", font=default, background="#363636", foreground="white")
w_label.grid(row=1, column=0)

entry2 = tk.Entry(frame, font=default, background="#363636", foreground="white")
entry2.config(width=20)
entry2.grid(row=1, column=1)

entry2.bind("<Return>", get_height)

calculate = tk.Button(frame, text="Calculate", font=default, background="#363636", command=bmi, foreground="white")
calculate.grid(row=3, column=1, columnspan=2)

result = tk.Label(frame, text="", font=default, background="#363636", foreground="white")
result.grid(row=4, column=0)

note = tk.Label(frame, text="\nNOTE: Press 'Enter' after typing your input.", background="#363636", font=("Arial", 10), foreground="white")
note.grid(row=6, column=0, pady=0)

root.mainloop()

