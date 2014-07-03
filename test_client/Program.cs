using System;
using System.Collections.Generic;
using System.Windows.Forms;
using System.Net;
using System.Net.Sockets;
using System.Text;

namespace test_client
{
    // http://professorweb.ru/my/csharp/web/level3/3_2.php

    static class Program
    {
        /// <summary>
        /// Главная точка входа для приложения.
        /// </summary>
        [STAThread]
        static void Main()
        {
            try
            {
                SendMessageFromSocket(27015);
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.ToString());
            }
            finally
            {
                Console.ReadLine();
            }

        }

        static void SendMessageFromSocket(int port)
        {
            // Буфер для входящих данных
            byte[] bytes = new byte[1024];

            // Соединяемся с удаленным устройством

            // Устанавливаем удаленную точку для сокета
            IPHostEntry ipHost = Dns.GetHostEntry("localhost");
            IPAddress ipAddr = ipHost.AddressList[1];
            IPEndPoint ipEndPoint = new IPEndPoint(ipAddr, port);

            Socket sender = new Socket(ipAddr.AddressFamily, SocketType.Stream, ProtocolType.Tcp);

            // Соединяем сокет с удаленной точкой
            sender.Connect(ipEndPoint);

            string message;
            do
            {
                Console.Write("Введите сообщение: ");
                message = Console.ReadLine();

                Console.WriteLine("Сокет соединяется с {0} ", sender.RemoteEndPoint.ToString());
                byte[] msg = Encoding.UTF8.GetBytes(message);

                // Отправляем данные через сокет
                int bytesSent = sender.Send(msg);

                // Получаем ответ от сервера
                int bytesRec = sender.Receive(bytes);

                Console.WriteLine("\nОтвет от сервера: {0}\n\n", Encoding.UTF8.GetString(bytes, 0, bytesRec));
            }
            while (message.Length > 1);

            // Освобождаем сокет
            sender.Shutdown(SocketShutdown.Both);
            sender.Close();
        }
    }
}
