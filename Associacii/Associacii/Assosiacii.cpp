//Two diricted conection
#include <iostream>
#include <string>
#include <vector>

//Поскольку отношения двунаправленные, между этими классами,
//для класса Doctor нужно использовать предварительное обявление
class Doctor;

class Patient {
private:
  std::string m_name;
  std::vector<Doctor *> m_doctor;

  //addDoctor обявляем закрытым, т.к. не хотим его публичного испольхования
  //доступ к нему осуществляется через Doctor::addPatient().
  void addDoctor(Doctor *doc);

public:
  Patient(std::string name) :m_name(name) {
	
  }

  friend std::ostream &operator << (std::ostream &out, const Patient &pat);
  std::string getName() const {
	return m_name;
  }

  //Делаем класс Doctor дружественным, чтобы иметь доступ к закрытому методу addDoctor()
  //(friend)класс Patient открывает Doctor свои закрытые классы
  //Мы не можем сделать дружественным метод addDoctor(), т.к. class Doctor предварительно обявлен
  friend class Doctor;
};

class Doctor {
private:
  std::string m_name;
  std::vector<Patient *>m_patient;

public:
  Doctor(std::string name) :m_name(name) {
	
  }

  void addPatient(Patient *pat) {
  //Врач добавляет Пациента
  m_patient.push_back(pat);

  //Пациент добавляет Врача
  pat->addDoctor(this);
  
  }

  friend std::ostream &operator << (std::ostream &out, const Doctor &doc) {
	unsigned int length = doc.m_patient.size();
	if (length == 0) {
	  out << doc.m_name << " has no patients right now ";
	  return out;
	}

	out << doc.m_name << " is seeing patients: ";
	for (unsigned int count = 0; count < length; ++count)
	  out << doc.m_patient[count]->getName() << ' ';

	return out;
  }

	std::string getName() const {
	  return m_name;
	}
};

void Patient::addDoctor(Doctor *doc) {
	m_doctor.push_back(doc);
}

std::ostream &operator <<(std::ostream &out, const Patient &pat) {
	unsigned int length = pat.m_doctor.size();
	if (length == 0) {
		out << pat.getName() << " has no doctors right now ";
		return out;
	}

	out << pat.m_name << " is seeng doctors: ";
	for (unsigned int count = 0; count < length; ++count)
		out << pat.m_doctor[count]->getName() << ' ';

	return out;
}

int main() {
//Создаем пациентов вне области видимости класса Doctor
	Patient *p1 = new Patient("Anton");
	Patient *p2 = new Patient("Ivan");
	Patient *p3 = new Patient("Derec");

	Doctor *d1 = new Doctor("John");
	Doctor *d2 = new Doctor("Tom");

	d1->addPatient(p1);

	d2->addPatient(p1);
	d2->addPatient(p3);

	std::cout << *d1 << '\n';
	std::cout << *d2 << '\n';
	std::cout << *p1 << '\n';
	std::cout << *p2 << '\n';
	std::cout << *p3 << '\n';

	delete p1;
	delete p2;
	delete p3;

	delete d1;
	delete d2;

	return 0;

}
