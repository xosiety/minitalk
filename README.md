
# 📖 Minitalk

small data exchange program using UNIX signals.

<!-- TOC -->
* [📖 Minitalk](#-minitalk)
* [💡 Introduzione](#-introduzione)
  * [📝 Mandatory part](#-mandatory-part)
  * [Server](#server)
  * [Client](#client)
  * [⏭️ Bonus](#-bonus)
* [🛠️ Sigaction](#-sigaction)
<!-- TOC -->

# 💡 Introduzione

L'obiettivo del progetto è creare un sistema di trasmissione di messaggi semplice ma funzionale utilizzando i segnali Unix come mezzo di comunicazione. Il mittente invia un messaggio al destinatario convertendo il messaggio in sequenze di segnali.

Ecco un riassunto delle funzioni permesse all'interno del progetto con i relativi link al manuale.

| Funzione                                                                            | Riassunto                                                                                                                                                                                                                                                                   |
|-------------------------------------------------------------------------------------|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| [`malloc`](https://man7.org/linux/man-pages/man3/free.3.html)                       | La funzione `malloc` viene utilizzata in C per allocare memoria dinamicamente durante l'esecuzione di un programma. Prende come argomento la dimensione in byte della memoria richiesta e restituisce un puntatore alla memoria allocata.                                   |
| [`free`](https://man7.org/linux/man-pages/man3/free.3.html)                         | La funzione `free` viene utilizzata per liberare la memoria precedentemente allocata tramite `malloc` o altre funzioni di allocazione della memoria. Libera la memoria specificata dal puntatore passato come argomento, consentendo al sistema operativo di riutilizzarla. |
| [`write`](https://man7.org/linux/man-pages/man2/write.2.html)                       | La funzione `write` consente di scrivere dati in un file o in un descrittore di file. Prende come argomenti il descrittore di file, il buffer dei dati e la dimensione dei dati da scrivere. Restituisce il numero di byte scritti o -1 in caso di errore.                  |
| [`getpid`](https://man7.org/linux/man-pages/man2/getpid.2.html)                     | La funzione `getpid` restituisce l'ID del processo chiamante. L'ID del processo è un numero univoco assegnato dal sistema operativo a ogni processo in esecuzione nel sistema.                                                                                              |
| [`signal`](https://man7.org/linux/man-pages/man2/signal.2.html)                     | La funzione `signal` viene utilizzata per impostare il comportamento di un programma in risposta a segnali specifici inviati dal sistema operativo o da altri processi. Prende come argomenti il segnale da gestire e il gestore di segnale personalizzato.                 |
| [`sigemptyset & sigaddset`](https://man7.org/linux/man-pages/man3/sigsetops.3.html) | Le funzioni `sigemptyset` e `sigaddset` sono utilizzate per inizializzare e modificare un insieme di segnali. `sigemptyset` svuota un insieme di segnali, mentre `sigaddset` aggiunge un segnale all'insieme.                                                               |
| [`sigaction`](https://man7.org/linux/man-pages/man2/sigaction.2.html)               | La funzione `sigaction` viene utilizzata per impostare il comportamento di un programma in risposta a segnali specifici. Consente di specificare un gestore di segnale personalizzato e altre opzioni per la gestione dei segnali.                                          |
| [`pause`](https://man7.org/linux/man-pages/man2/pause.2.html)                       | La funzione `pause` sospende l'esecuzione di un programma fino a quando non viene ricevuto un segnale. Viene comunemente utilizzata per bloccare un processo fino a quando non viene ricevuto un segnale di terminazione o un altro segnale specificato.                    |
| [`kill`](https://man7.org/linux/man-pages/man2/kill.2.html)                         | La funzione `kill` viene utilizzata per inviare un segnale a un processo specificato da un ID. Può essere utilizzata per inviare segnali di terminazione o per interagire con altri processi.                                                                   |
| [`sleep`](https://man7.org/linux/man-pages/man3/sleep.3.html)                       | La funzione `sleep` sospende l'esecuzione di un programma per un numero specificato di secondi. È utile per introdurre un ritardo nell'esecuzione di un programma o per attendere un certo periodo di tempo.                                                                |
| [`usleep`](https://man7.org/linux/man-pages/man3/usleep.3.html)                     | La funzione `usleep` sospende l'esecuzione di un programma per un numero specificato di microsecondi. Funziona in modo simile alla funzione `sleep`, ma accetta una frazione di secondo più piccola come argomento.                                                         |                                                                                                                                                                  
| [`exit`](https://man7.org/linux/man-pages/man3/exit.3.html)                         | La funzione `exit` viene utilizzata per terminare l'esecuzione di un programma in modo volontario. Può anche essere utilizzata per restituire un codice di stato al sistema operativo.                                                                                   

## 📝 Mandatory part

Produrre eseguibili per il server e il client.

Il client deve comunicare una stringa passata come parametro al server (identificato dal suo ID di processo), che la visualizza successivamente utilizzando solo i segnali SIGUSR1 e SIGUSR2.

In Unix, i segnali sono meccanismi utilizzati per comunicare con i processi. I segnali sono eventi asincroni che possono essere generati dal kernel del sistema operativo, da altri processi o anche da un processo stesso. Ogni segnale ha un numero di identificazione univoco associato ad esso.

I segnali SIGUSR1 e SIGUSR2 sono segnali definiti dall'utente (User-Defined Signals). Questi segnali sono generalmente utilizzati come meccanismi di comunicazione tra processi o per inviare notifiche personalizzate.

Quando un processo riceve un segnale, può scegliere di gestirlo o ignorarlo. Per gestire un segnale, un processo deve definire un gestore di segnali (signal handler). Un signal handler è una funzione che viene eseguita quando il processo riceve un determinato segnale. Per impostare un signal handler per un segnale specifico, il processo utilizza la funzione di libreria `signal()`.

Ecco un esempio di codice che mostra come impostare e gestire i segnali SIGUSR1 e SIGUSR2 in C utilizzando la funzione `signal()`:

```c
#include <stdio.h>
#include <unistd.h>
#include <signal.h>

// Signal handler per SIGUSR1
void sigusr1_handler(int signum) {
    printf("Ricevuto SIGUSR1\n");
    // Esegui le azioni desiderate
}

// Signal handler per SIGUSR2
void sigusr2_handler(int signum) {
    printf("Ricevuto SIGUSR2\n");
    // Esegui le azioni desiderate
}

int main() {
    // Imposta i signal handler per SIGUSR1 e SIGUSR2
    signal(SIGUSR1, sigusr1_handler);
    signal(SIGUSR2, sigusr2_handler);

    // Esegui il programma
    while(1) {
        // Esegui le azioni del programma
        sleep(1);
    }

    return 0;
}
```

Nell'esempio sopra, vengono definiti due signal handler: `sigusr1_handler()` per SIGUSR1 e `sigusr2_handler()` per SIGUSR2. Questi signal handler vengono quindi associati ai segnali corrispondenti utilizzando `signal(SIGUSR1, sigusr1_handler)` e `signal(SIGUSR2, sigusr2_handler)`.

Il programma entra quindi in un ciclo while che esegue le azioni principali. Nel frattempo, se il processo riceve SIGUSR1 o SIGUSR2, verranno eseguiti i rispettivi signal handler.

## Server 

```c
void ft_btoa(int sig, siginfo_t *info, void *context)
{
	static int bit;
	static int i;

	(void)context; // Ignora il parametro non utilizzato per evitare un warning del compilatore

	if (sig == SIGUSR1)
		i |= (0x01 << bit); // Imposta il bit corrente a 1
	bit++;

	if (bit == 8)
	{
		if (i == 0)
			kill(info->si_pid, SIGUSR2); // Invia un segnale SIGUSR2 come conferma
		ft_printf("%c", i); // Stampa il carattere corrispondente al valore intero i
		bit = 0;
		i = 0;
	}
}
```

- `static int bit;`: Viene dichiarata una variabile `bit` di tipo intero in modo che il suo valore persista tra le chiamate alla funzione. Questa variabile tiene traccia del bit corrente nel processo destinatario.

- `static int i;`: Viene dichiarata una variabile `i` di tipo intero, anch'essa statica, che rappresenta il valore intero del carattere in fase di costruzione.

- `(void)context;`: Questa riga viene utilizzata per evitare un warning del compilatore riguardante il parametro `context` non utilizzato. Ignora il parametro senza effettuare alcuna operazione.

- `if (sig == SIGUSR1)`: Controlla se il segnale ricevuto è `SIGUSR1`. Questo indica che il bit corrente nel messaggio è 1.

- `i |= (0x01 << bit);`: Utilizzando l'operatore OR bit a bit con l'operazione di shift a sinistra, viene impostato il bit corrente di `i` a 1.

- `bit++;`: Incrementa il valore di `bit` per passare al bit successivo nel messaggio.

- `if (bit == 8)`: Controlla se sono stati processati tutti gli 8 bit del carattere.

- `if (i == 0)`: Verifica se il valore di `i` è 0, il che indica che il carattere corrente è un carattere null.

- `kill(info->si_pid, SIGUSR2);`: Invia un segnale `SIGUSR2` al processo mittente come conferma di ricezione del messaggio.

- `ft_printf("%c", i);`: Stampa il carattere corrispondente al valore intero `i`.

- `bit = 0;`: Reimposta il valore di `bit` a 0 per processare il prossimo carattere.

- `i = 0;`: Reimposta il valore di `i` a 0 per iniziare a costruire il prossimo carattere.

il seguente codice riceve i segnali inviati dal mittente e li converte in un messaggio binario leggibile.

```c
int main(int argc, char **argv)
{
	int pid;
	struct sigaction act;

	(void)argv; // Ignora il parametro non utilizzato per evitare un warning del compilatore

	if (argc != 1)
	{
		ft_printf("Error\n");
		return (1);
	}

	pid = getpid(); // Ottiene il PID del processo destinatario
	ft_printf("%d\n", pid); // Stampa il PID

	act.sa_sigaction = ft_btoa; // Imposta il signal handler personalizzato ft_btoa
	sigemptyset(&act.sa_mask); // Inizializza il set di segnali vuoto
	act.sa_flags = 0;

	while (argc == 1)
	{
		sigaction(SIGUSR1, &act, NULL); // Imposta il signal handler per SIGUSR1
		sigaction(SIGUSR2, &act, NULL); // Imposta il signal handler per SIGUSR2
		pause(); // Sospende il processo fino alla ricezione di un segnale
	}

	ft_putchar_fd('\n', 1); // Stampa una nuova riga
	return (0);
}
```

- `struct sigaction act;`: Viene dichiarata una variabile di tipo `struct sigaction` per impostare il comportamento dei signal handler.

- `(void)argv;`: Questa riga viene utilizzata per evitare un warning del compilatore riguardante il parametro `argv` non utilizzato. Ignora il parametro senza effettuare alcuna operazione.

- `if (argc != 1)`: Verifica se ci sono argomenti extra passati al programma. Se sì, viene stampato un messaggio di errore e il programma termina con un codice di uscita 1.

- `pid = getpid();`: Utilizza la funzione `getpid()` per ottenere il PID (Process ID) del processo destinatario.

- `ft_printf("%d\n", pid);`: Stampa il PID del processo destinatario seguito da una nuova riga.

- `act.sa_sigaction = ft_btoa;`: Imposta il signal handler personalizzato `ft_btoa` nella struttura `act.sa_sigaction`.

- `sigemptyset(&act.sa_mask);`: Inizializza il set di segnali vuoto nella struttura `act.sa_mask`. Questo indica che non ci sono segnali che devono essere bloccati durante l'esecuzione del signal handler.

- `act.sa_flags = 0;`: Imposta i flag di `act` a 0. Non vengono utilizzati flag aggiuntivi.

- `while (argc == 1)`: Entra in un ciclo che si ripete finché `argc` è uguale a 1, il che significa che non sono stati passati argomenti extra al programma.

- `sigaction(SIGUSR1, &act, NULL);`: Imposta il signal handler `ft_btoa` per il segnale `SIGUSR1` utilizzando la chiamata di sistema `sigaction()`.

- `sigaction(SIGUSR2, &act, NULL);`: Imposta il signal handler `ft_btoa` per il segnale `SIGUSR2` utilizzando la chiamata di sistema `sigaction()`.

- `pause();`: Sospende l'esecuzione del processo fino a quando non viene ricevuto un segnale. Quando viene ricevuto un segnale, il signal handler `ft_btoa` viene chiamato per gestirlo.

- `ft_putchar_fd('\n', 1);`: Stampa una nuova riga dopo che il ciclo `while` è terminato.

- `return (0);`: Termina il programma con un codice di uscita 0, indicando che il programma è stato eseguito correttamente.

## Client

La funzione `ft_atob` viene utilizzata per convertire un carattere in binario e inviare i segnali corrispondenti al processo destinatario identificato dal PID fornito.

```c
void ft_atob(int pid, char c)
{
	int bit;

	bit = 0;
	while (bit < 8)
	{
		if ((c & (0x01 << bit)))
			kill(pid, SIGUSR1); // Invia il segnale SIGUSR1 al processo destinatario se il bit corrente è 1
		else
			kill(pid, SIGUSR2); // Invia il segnale SIGUSR2 al processo destinatario se il bit corrente è 0
		usleep(500); // Attende per un breve periodo di tempo (500 microsecondi) prima di inviare il segnale successivo
		bit++;
	}
}
```

- `bit = 0;`: Inizializza la variabile `bit` a 0, che rappresenterà la posizione del bit corrente durante la conversione in binario.

- `while (bit < 8)`: Itera finché il bit corrente è inferiore a 8, rappresentando i 8 bit del carattere.

- `if ((c & (0x01 << bit)))`: Controlla se il bit corrente del carattere è 1. Utilizzando l'operatore di bitwise AND (`&`) tra `c` e un valore che ha un bit impostato nella posizione corrente (`0x01 << bit`), si verifica se il bit è 1.

- `kill(pid, SIGUSR1);`: Se il bit corrente è 1, viene inviato il segnale `SIGUSR1` al processo destinatario identificato dal PID fornito.

- `else`: Altrimenti, se il bit corrente è 0.

- `kill(pid, SIGUSR2);`: Viene inviato il segnale `SIGUSR2` al processo destinatario identificato dal PID fornito.

- `usleep(500);`: Aggiunge una breve pausa di 500 microsecondi prima di inviare il segnale successivo. Questo serve a garantire che il processo destinatario abbia il tempo di gestire il segnale prima di riceverne un altro.

- `bit++;`: Incrementa il valore di `bit` per passare al bit successivo durante la conversione in binario.

In sintesi, la funzione `ft_atob` invia una sequenza di segnali `SIGUSR1` o `SIGUSR2` al processo destinatario per rappresentare i bit del carattere fornito.

Il programma mittente, invece, invia un messaggio binario al processo server utilizzando i segnali UNIX.

```c
int main(int argc, char **argv)
{
	int pid;
	int i;

	i = 0;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]); // Converte il secondo argomento in un intero (PID del processo destinatario)
		while (argv[2][i] != '\0')
		{
			ft_atob(pid, argv[2][i]); // Converte il carattere in binario e invia i segnali corrispondenti al processo destinatario
			i++;
		}
		signal(SIGUSR2, confirm_msg); // Imposta il signal handler per SIGUSR2 per confermare la ricezione del messaggio
		ft_atob(pid, '\0'); // Invia un carattere nullo come fine del messaggio
	}
	else
	{
		ft_printf("Error\n");
		return (1);
	}

	return (0);
}
```

- `if (argc == 3)`: Controlla se ci sono esattamente tre argomenti passati al programma, il che indica che è stato fornito il PID del processo destinatario e il messaggio da inviare.

- `pid = ft_atoi(argv[1]);`: Converte il secondo argomento passato (argv[1]) in un intero utilizzando la funzione `ft_atoi` e lo assegna alla variabile `pid`. Questo rappresenta il PID del processo destinatario.

- `while (argv[2][i] != '\0')`: Itera attraverso i caratteri del messaggio (argv[2]) fino a quando non viene raggiunto il carattere di fine stringa ('\0').

- `ft_atob(pid, argv[2][i]);`: Invoca la funzione `ft_atob` per convertire il carattere in binario e inviare i segnali corrispondenti al processo destinatario identificato dal PID.

- `signal(SIGUSR2, confirm_msg);`: Imposta il signal handler `confirm_msg` per il segnale `SIGUSR2`. Questo signal handler viene chiamato quando il processo destinatario invia il segnale `SIGUSR2` come conferma di ricezione del messaggio.

- `ft_atob(pid, '\0');`: Invia un carattere nullo ('\0') come fine del messaggio per indicare al processo destinatario che il messaggio è completo.

- `else`: Viene eseguito se il numero di argomenti non è corretto (diverso da 3). Viene stampato un messaggio di errore e il programma termina con un codice di uscita 1.

- `return (0);`: Termina il programma con un codice di uscita 0, indicando che il programma è stato eseguito correttamente.


## ⏭️ Bonus

Per quel che riguarda la parte bonus andremo ad aggiungere una conferma di ricezione.

```c
void confirm_msg(int signal)
{
	if (signal == SIGUSR2)
		ft_printf("Message Received\n");
}
```

La funzione `confirm_msg` è un signal handler che viene chiamato quando il processo destinatario riceve un segnale `SIGUSR2`. Se il segnale ricevuto corrisponde a `SIGUSR2`, viene stampato un messaggio che indica che il messaggio è stato ricevuto con successo.

Il progetto bonus dovra' supportare anche caratteri Unicode. 

Sara' fondamentale conoscere le differenze tra *sigaction* e *signal*
Ecco una tabella che evidenzia le differenze tra `signal` e `sigaction`:

| Caratteristica                                                              | `signal`                                    | `sigaction`                                                                                                                    |
|-----------------------------------------------------------------------------|---------------------------------------------|--------------------------------------------------------------------------------------------------------------------------------|
| Tipo di gestore di segnali                                                  | Puntatore a funzione (`void (*handler)()`)  | Struttura `struct sigaction` contenente un membro `sa_handler` che può essere un puntatore a funzione                          |
| Gestione dell'insieme dei segnali bloccati durante l'esecuzione del gestore | Non specificato                             | `struct sigaction` contiene un membro `sa_mask` per l'insieme dei segnali bloccati durante l'esecuzione del gestore di segnali |
| Opzioni aggiuntive                                                          | Non specificato                             | `struct sigaction` contiene un membro `sa_flags` per specificare opzioni aggiuntive                                            |
| Compatibilità                                                               | Standard ANSI C                             | Standard POSIX                                                                                                                 |
| Comportamento predefinito per i segnali ignorati                            | Reimposta al comportamento predefinito      | Non reimposta il comportamento predefinito per i segnali ignorati                                                              |
| Compatibilità con altre chiamate di sistema che utilizzano segnali          | Potenziali problemi di compatibilità        | Meno probabilità di problemi di compatibilità                                                                                  |

È importante notare che le differenze possono variare a seconda del sistema operativo e delle implementazioni specifiche.

# 🛠️ Sigaction

La funzione `sigaction` viene utilizzata per gestire i segnali in un programma UNIX. Essa permette di modificare il comportamento predefinito di un segnale quando viene ricevuto.

La sua dichiarazione è la seguente:

```c
int sigaction(int signum, const struct sigaction *act, struct sigaction *oldact);
```

- `signum`: È il numero del segnale che si desidera gestire. Può essere un valore costante come `SIGUSR1` o `SIGUSR2`, che rappresentano segnali utente definiti dall'utente.

- `act`: È un puntatore a una struttura `struct sigaction` che specifica l'azione da associare al segnale `signum`. La struttura `struct sigaction` ha i seguenti campi principali:
    - `void (*sa_handler)(int)`: Il puntatore a una funzione che viene eseguita quando il segnale viene ricevuto. Può essere specificato come `SIG_DFL` per ripristinare il comportamento predefinito del segnale o `SIG_IGN` per ignorare il segnale.
    - `void (*sa_sigaction)(int, siginfo_t *, void *)`: Opzionale. Il puntatore a una funzione con una firma più estesa che può ricevere informazioni aggiuntive sul segnale tramite la struttura `siginfo_t`.
    - `sigset_t sa_mask`: Un insieme di segnali che vengono bloccati durante l'esecuzione della funzione di gestione del segnale.
    - `int sa_flags`: Opzioni per personalizzare il comportamento della gestione del segnale, come `SA_RESTART` per riavviare le chiamate di sistema interrotte dal segnale.

- `oldact`: È un puntatore a una struttura `struct sigaction` che può contenere informazioni sull'azione precedente associata al segnale.

La funzione `sigaction` restituisce 0 in caso di successo e -1 in caso di errore.

Quando un segnale viene ricevuto e associato a un'azione tramite `sigaction`, la funzione o il gestore specificato viene chiamato, consentendo di eseguire un'azione personalizzata o di gestire il segnale in modo diverso rispetto al comportamento predefinito.

In sintesi, `sigaction` consente di definire una funzione di gestione personalizzata per un segnale specifico, consentendo di controllare il comportamento del programma quando tale segnale viene ricevuto.

  