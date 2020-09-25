/**
*Ballot class is used to track Candidates within the context of one competition
*		Holds an ArrayList of Candidates and the office's name
*/

import java.util.ArrayList;
public class Ballot
{
	//* arrayList of all the candidates in the election*/
	protected ArrayList<Candidate> candidateList;
	//* name of position candidates are running for*/
	private String officeName;

	/**
	*	Construct a Ballot
	* @param officeName for which candidats are running
	*/
	public Ballot(String officeName)
	{
		this.officeName = officeName;
		this.candidateList = new ArrayList<Candidate> ();
	}

	/**
	* returns position candidates are running for
	* @return officeName
	*/
	public String getOfficeName()
	{		return officeName;		}

	/**
	* adds a candidate to arrayList of all candidates
	* @param Candidate object
	*/
	public void addCandidate(Candidate c)
	{ 	candidateList.add(c);		}

	/**
	*	returns an array list of all candidates in election
	* @return ArrayList<Candidate>
	*/
	public ArrayList<Candidate> getCandidates()
	{		return this.candidateList;		}
}
