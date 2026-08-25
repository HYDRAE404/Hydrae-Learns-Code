using System;
using System.Threading;
using System.Threading.Tasks;

class Program
{
    // The condition flag
    static bool isConditionMet = false;

    static async Task Main()
    {
        Console.CursorVisible = false; // Hide cursor for cleaner look
        
        // Simulate an external condition that takes 5 seconds to resolve
        _ = Task.Run(async () =>
        {
            await Task.Delay(5000); 
            isConditionMet = true; 
        });

        int total = 100;
        int currentProgress = 0;
        Random random = new Random();

        while (currentProgress < total)
        {
            int step;
            int delay;

            if (!isConditionMet)
            {
                // --- LAGGING STATE ---
                // Progress barely moves or stays stuck
                step = random.Next(0, 2); // 50% chance it doesn't move at all
                
                // Progress is hard-capped at 85% so it never finishes while lagging
                if (currentProgress >= 85) step = 0; 

                // Long, painful freezes (0.5 to 1.5 seconds)
                delay = random.Next(500, 1500); 
            }
            else
            {
                // --- CONDITION MET STATE ---
                // Progress jumps forward quickly
                step = random.Next(2, 6); 
                
                // Smooth, fast execution (10 to 40 milliseconds)
                delay = random.Next(10, 40); 
            }

            currentProgress = Math.Min(currentProgress + step, total);
            DrawProgressBar(currentProgress, total, !isConditionMet);

            await Task.Delay(delay); // Using async delay to keep UI responsive
        }

        Console.WriteLine("\n\nSuccess: Process finalized successfully!");
        Console.CursorVisible = true;
    }

    static void DrawProgressBar(int progress, int total, bool isLagging)
    {
        int barSize = 30;
        int filledCount = (int)((double)progress / total * barSize);
        int percent = (int)((double)progress / total * 100);

        string bar = new string('█', filledCount) + new string('-', barSize - filledCount);
        
        // Visual indicator changing based on the lag state
        string status = isLagging ? "[Connecting... Stalled]" : "[Connected! Syncing ]";
        
        Console.Write($"\r{status} [{bar}] {percent,3}%");
    }
}
