/**
* BallotReader class is used to read a given file and create a Ballot object
*		has readFile to hold file from a BufferedReader, office to parse the name of office for which Candidates contest
*   and amtCandidates to parse the # Candidates. newBallot holds the ballot created from the file
*		Variables used in creating a Candidate to add to the ballot: cName, cAffiliation, ballotLine, nameAndAffiliation
*/

import java.io.IOException;
import java.io.*;
import java.util.Scanner;
import java.lang.*;
 // imported

public class BallotReader
{
	/**
	* reads a file of data and creates a new instance of Ballot class
	* @param filename name of file to find on computer running programs
	* @return newBallot returns the ballot created in method
	*/
	public static Ballot readBallot(String filename)
	throws IOException
	{
		/*Initialize new Ballot object*/
		Ballot newBallot = null;
		/*Use try syntax to allow a thrown exception*/
		try (BufferedReader readFile = new BufferedReader(new FileReader(filename)) )
		{
		//create a BufferedReader from FileReader so that we can use the readLine method in BufferedReader class (this method is not present in FileReader)
		String office = readFile.readLine();
		/*instantiate a new Ballot object*/
		newBallot = new Ballot(office);
		int amtCandidates = Integer.parseInt(readFile.readLine());
		/* Instantiate variables used to move data from new file to a Candidate Object*/
		String cName;
		String cAffiliation;
		String ballotLine;
		String[] nameAndAffiliation; //array to hold pieces of ballotLine

		/*Loop through 3rd+ lines of the input file*/
		for (int i = 0; i < amtCandidates; i++){
			ballotLine = readFile.readLine(); //get line from file
			nameAndAffiliation = ballotLine.split(";"); //use String method "split" to parse the line,
			 																						////around ";" delimiter
			cName = nameAndAffiliation[0];
			cAffiliation = nameAndAffiliation[1];
			//add front and back halves of ballotLine into a new Candidate
			newBallot.addCandidate(new Candidate(cName, cAffiliation));
			//Candidate is added to the new ballot
		} // 	END TRY BLOCK
	}
		return newBallot;
	}
}
