using CalculatorLib;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Calculator
{
    class Program
    {
        static void Main(string[] args)
        {
            double result = Calculate.Add(1, 2);
            Console.WriteLine($"Add(1, 2) = {result}\n");

            result = Calculate.Subtract(1, 2);
            Console.WriteLine($"Subtract(1, 2) = {result}\n");

            result = Calculate.Multiply(1, 2);
            Console.WriteLine($"Multiply(1, 2) = {result}\n");

            result = Calculate.Divide(1, 2);
            Console.WriteLine($"Divide(1, 2) = {result}\n");


            Console.ReadLine();
        }
    }
}
