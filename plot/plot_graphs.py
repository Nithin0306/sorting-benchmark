import os
import pandas as pd
import matplotlib.pyplot as plt

BASE_DIR = os.path.dirname(os.path.abspath(__file__))
CSV_PATH = os.path.join(BASE_DIR, "..", "results", "results.csv")
CSV_PATH = os.path.normpath(CSV_PATH)

if not os.path.exists(CSV_PATH):
    raise FileNotFoundError(f"CSV not found at: {CSV_PATH}")

df = pd.read_csv(CSV_PATH)

RESULTS_DIR = os.path.join(BASE_DIR, "..", "results")
os.makedirs(RESULTS_DIR, exist_ok=True)

cases = ["BEST", "AVERAGE", "WORST"]


for case in cases:
    temp = df[df["CASE"] == case]

    plt.figure(figsize=(12, 7))

    for algo in temp["ALGORITHM"].unique():
        a = temp[temp["ALGORITHM"] == algo]
        y = a["COMPARISONS"].values

        if (y == 0).all():
            y = [1] * len(y)  

        plt.plot(
            a["SIZE"],
            y,
            marker='o',
            linewidth=2,
            label=algo
        )

    plt.title(f"Comparisons – {case} Case (LOG SCALE)", fontsize=16)
    plt.xlabel("Input Size (n)", fontsize=14)
    plt.ylabel("Comparisons (log scale)", fontsize=14)

    plt.yscale("log")

    plt.grid(True, which="both", linestyle='--', alpha=0.6)
    plt.legend(fontsize=12)

    out_path = os.path.join(RESULTS_DIR, f"{case.lower()}_case_log.png")
    plt.savefig(out_path, dpi=300, bbox_inches='tight')
    plt.close()

print("Log-scale graphs generated successfully!")
