using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1
{
  class Instrumento
  {
    public string nombre;
    public tipoInstrumento tipo;
    
    public enum tipoInstrumento { Cuerda, Viento, Percusion }

    public Instrumento() { }

    public Instrumento(string nombre, string lugar, tipoInstrumento tipo)
    {
      this.nombre = nombre;
      this.tipo = tipo;
    }

    public Instrumento(string nombre, tipoInstrumento cuerda)
    {
      this.nombre = nombre;
    }

    public void setNombre(string nombre)
    {
      this.nombre = nombre;
    }

    public string getNombre()
    {
      return this.nombre;
    }

    public void setTipo(tipoInstrumento tipo )
    {
      this.tipo = tipo;
    }

    public string getInstrumentoToString()
    {

      StringBuilder stb = new StringBuilder();
      stb.AppendFormat("\nNombre Instrumento: {0}, Tipo Instrumento: {1}\n", this.nombre, this.tipo);
      return stb.ToString();
    }
  }
}
