using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Moneychange
{
    class Program
    {
        static long moneyChange(long n,long [] COINS)
        {
            long[] MinNumCoins = new long[n + 1];
            MinNumCoins[0] = 0;
            for (int i = 1; i < n + 1; i++)
            {
                MinNumCoins[i] = long.MaxValue;
            }

            for (int i = 0; i < n + 1; i++)
            {
                for (int j = 0; j < COINS.Length; j++)
                {
                    if (i >= COINS[j])
                    {
                        long NumCoins = MinNumCoins[i - COINS[j]] + 1;
                        if (NumCoins < MinNumCoins[i])
                        {
                            MinNumCoins[i] = NumCoins;
                        }
                    }
                }
            }
            return MinNumCoins[n];
        }

        static void Main(string[] args)
        {
            long[] COINS = { 1, 5, 10 };
            Console.WriteLine(moneyChange(24, COINS));
            
        }
    }
}
