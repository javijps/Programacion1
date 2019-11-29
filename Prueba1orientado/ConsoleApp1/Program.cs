using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1
{
  class Program
  {
    static void Main(string[] args)
    {
      Orquesta orDos = new Orquesta("Orquesta Buenos Aires", "La Boca", Orquesta.tipoOrquesta.Sinfonica);
      //Console.WriteLine("Nombre: {0}, Apellido: {1}, Edad: {2}", orDos.nombre, orDos.lugar, orDos.tipo);
      //Console.ReadLine();

      Instrumento ins = new Instrumento("Violin",Instrumento.tipoInstrumento.Cuerda);
      //Console.WriteLine("Instrumento: {0}, Tipo: {1}", ins.nombre,ins.tipo);
      //Console.ReadLine();

      Musico mus = new Musico("Juan", "Perez", 30,ins,orDos);
      Console.WriteLine("Nombre: {0}, Apellido: {1}, Edad: {2} {3}{4}", mus.nombre,mus.apellido,mus.edad,mus.inst.getInstrumentoToString(), mus.orq.getOrquestaToString());
      Console.ReadLine();

    }
  }
}
