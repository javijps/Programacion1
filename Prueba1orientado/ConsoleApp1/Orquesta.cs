using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1
{
  class Orquesta
  {
    public string nombre;
    public string lugar;
    public tipoOrquesta tipo;

    public enum tipoOrquesta {Sinfonica, Camara, Filarmonica }

    public Orquesta() { }

    public Orquesta(string nombre, string lugar, tipoOrquesta tipo)
    {
      this.nombre = nombre;
      this.lugar = lugar;
      this.tipo = tipo;
    }

    public void setNombre(string nombre)
    {
      this.nombre = nombre;
    }

    public string getNombre()
    {
      return this.nombre;
    }

    public string getOrquestaToString() {

      StringBuilder stb = new StringBuilder();
      stb.AppendFormat("Nombre Orquesta: {0}, Lugar: {1}, Tipo Orquesta: {2}\n", this.nombre, this.lugar, this.tipo);
      return stb.ToString();
    }

    public static void ImprimirOrquesta(Orquesta or)
    {
      StringBuilder sb = new StringBuilder();
      sb.AppendLine(or.getOrquestaToString());
      if (or.nombre.Count > 0)//aca va el musico
      {
        sb.AppendFormat("lISTA DE MUSICOS \n");
        foreach (Musico element in or.nombre)//aca va el musico
        {
          sb.AppendFormat("Nombre: {0}", element.nombre);
          sb.AppendFormat("Tipo: {0}", element.apellido);
        }
      }
    } 
  }
}
