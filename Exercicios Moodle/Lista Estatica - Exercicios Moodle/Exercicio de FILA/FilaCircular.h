void CriaFila(FilaCircular *f)
{
    f->quant = 0;
    f->inicio = 0;
    f->fim = -1;
}

int InserirNaFilaCircular(FilaCircular *f, elem *e)
{
    int pos;
    if (f->fim == MAX - 1)
    {
        pos = 0;
    }
    else
    {
        pos = f->fim + 1;
    }

    if (pos == f->inicio && f->quant > 0)
    {
        return -1;
    }

    else
    {
        f->L[pos] = *e;
        f->fim = pos;
        f->quant++;
        return 1;
    }
}

int RemoverDaFilaCircular(FilaCircular *f)
{
    if (f->quant == 0)
    {
        return -1;
    }
    else
    {
        f->quant--;
        f->inicio = f->inicio + 1;
        if (f->inicio == MAX)
        {
            f->inicio = 0;
        }
    }
    return 1;
}
